# make all

from io import StringIO
import os
import sys

import subprocess

print("Making targets...")

makefiles = subprocess.check_output("find -type f -name Makefile", shell=True).decode('utf-8').split('\n')

makefiles = filter(lambda m:m!="", makefiles)

for makefile in makefiles:
    print(makefile)
    path = "/".join(makefile.split("/")[:-1])        
    subprocess.check_output(f"cd {path} & make -f Makefile", shell=True).decode('utf-8').split('\n')
    
print("Running NDS...")

ndss = subprocess.check_output("find -type f -name \"*.nds\"", shell=True).decode('utf-8').split('\n')
ndss = filter(lambda m:m!="", ndss)

def execute(cmd):
    print(cmd)
    # https://stackoverflow.com/questions/4417546/constantly-print-subprocess-output-while-process-is-running
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)

for nds in ndss:
    nds = nds.replace('/','\\')
    print(nds)
    
    # run until "Passed X tests out of Y message"
        
    # not working....
    #for path in execute(["D:\\Software\\Emulators\\DeSmuMe\\DeSmuME_0.9.9_x64.exe", nds]):
    #    print(path, end="")
