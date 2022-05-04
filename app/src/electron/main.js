const { app } = require('electron')
const electronBrowserWindow = require('electron').BrowserWindow;
const electronDialog = require('electron').dialog;
const electronIpcMain = require('electron').ipcMain;

const fs = require('fs');

const { localStorage } = require('electron-browser-storage');

const nodePath = require("path");

const Menu = require('electron').menu;

const Store = require('electron-store');
const { fstat } = require('fs');

const store = new Store('project');

let window;

const menuTemplate = [
    {
        label: 'Help',
        submenu: [
            {
                label: 'Help',
                click: () => {
                    window.loadFile('./views/discord.html');
                }
            }
        ]
    }
];

//Creates Main Window
function createMainWindow() {
    const mainWindow = new electronBrowserWindow({
        width: 900,
        height: 600,
        show: false,
        webPreferences: {
            nodeIntegration: false,
            contextIsolation: true,
            preload: nodePath.join(__dirname, 'preload.js')
        }
    });

    mainWindow.loadFile('index.html')
        .then(() => { mainWindow.show(); });

    return mainWindow;
}
//Creates the Discord Window
function createDiscordWindow() {
    const discordWindow = new electronBrowserWindow({
        width: 450 * 1.5, 
        height: 300 * 1.5,
        show: false,
        webPreferences: {
            nodeIntegration: false,
            contextIsolation: true,
            preload: nodePath.join(__dirname, 'preload.js')
        }
    });

    discordWindow.loadFile('./views/discord.html')
        .then(() => { discordWindow.show(); });

    return discordWindow;
}
//Gets the .nds file to play
function getNDSPath() {
    fs.readdir(store.get('ProjectDir'), (err, files) => {
        if (err)
          console.log(err);
        else {
          //console.log("\nCurrent directory filenames:");
          files.forEach(file => {
            var rom = nodePath.parse(file).ext;
            if(rom == '.nds'){
                var MainPath = store.get('ProjectDir');
                store.set('ROMPath', MainPath + "\\" + file);
                emulatorWindow = openEmu();
            }
          })
        }
      })
}
//Opens the Emulator
function openEmu() {   

    const emulatorWindow = new electronBrowserWindow({
        width: 256 + 20, 
        height: 192 * 2 + 20,
        show: false,
        webPreferences: {
            nodeIntegration: false,
            contextIsolation: true,
            preload: nodePath.join(__dirname, 'preload.js')
        }
    });

    emulatorWindow.loadFile('./views/Emulator.html')
        .then(() => { emulatorWindow.show(); });
    return emulatorWindow;
}

app.on('ready', () => {
    //Menu.setApplicationMenu(menuTemplate);
    mainWindow = createMainWindow();
    discordWindow = createDiscordWindow();
});

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') {
        app.quit();
    }
});

app.on('activate', () => {
    if (electronBrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});

// -----

// Let's listen for a call on the 'getPath' channel
electronIpcMain.handle('getPath', async () => {
    // Dialog options.
    const options = {
        properties: ["openFile"],
        filters: [
            {
                name: "DSC Projects",
                extensions: ["DSCProj"],
            }
        ]
    }

    // When available, return the modified path back to the render thread via IPC
    return await openDialog(mainWindow, options)
        .then((result) => {
            // User cancelled the dialog
            if (result.canceled === true) { return; }

            let path = result.filePaths[0];

            if(result.canceled === true){
                return result.canceled;
            }
            else{
                store.set('ProjectDir', nodePath.parse(path).dir);
                return path;
            }
        })
})

function openDialog(parentWindow, options) {
    return electronDialog.showOpenDialog(parentWindow, options)
        .then((result) => { if (result) { return result; } })
        .catch((error) => { console.error('Show open dialog error: ' + error); });
}

electronIpcMain.handle('blankProject', async () => {

    console.log('hi');
    // Dialog options.
    const options = {
        filters: [
            {
                name: "DSC Projects",
                extensions: ["DSCProj"],
            }
        ]
    }

    // When available, return the modified path back to the render thread via IPC
    return await saveDialog(mainWindow, options)
        .then((result) => {
            // User cancelled the dialog
            if (result.canceled === true) { return; }

            let path = result.filePaths[0];

            if(result.canceled === true){
                return result.canceled;
            }
            else{
                store.set('ProjectDir', nodePath.parse(path).dir);
                return path;
            }
        })
})

function saveDialog(parentWindow, options) {
    return electronDialog.showSaveDialog(parentWindow, options)
        .then((result) => { if (result) { return result; } })
        .catch((error) => { console.error('Show open dialog error: ' + error); });
}

electronIpcMain.handle('openEmu', async () => {
    emulatorWindow = openEmu();
    return store.get('ROMPath');
})