# DSCEngine Tests

Where we make sure everything works the way it should do.

# DSCEngine Tests list

This is a list of tests that DSCEngine should pass.

## Legend

✅ - ok, seems to work, but wouldn't hurt to double check it

🍦 - other things may break if this doesn't work. Assume it's correct, although it has not been thoroughly tested

⚠️ - not tested, proceed with caution

❌ - successfully fails

🔵 - not a concern

🔸 - to be implemented

## Tests List

| No.  | Target                                 | Description                                                              | Passing |
|-----:|----------------------------------------|--------------------------------------------------------------------------|:-------:|
|    1 | `_logv()`                              | Check for incorrect parsings, index-out-of-bounds etc                    |✅| 
|    2 | `Event::trigger()`                     | Missed case: what if the EventHandler is null?                           |✅| 
|    3 | `ReadOnlyData::extract()`              | Possible "8-bit write to VRAM" error source                              |⚠️| 
|    4 | `ReadOnlyData::extract()`              | Extracting resources from file                                           |⚠️| 
|    5 | `ReadOnlyData::extract(v*,i,i)`        | Check requested data alignment                                           |✅| 
|    6 | `AssetData::*`                         | It is assumed that provided AssetData sources are correctly created      |⚠️/🔵?| 
|    7 | `AssetData::*`                         | Data access with compression enabled                                     |🔸| 
|    8 | `AssetData::get_color_depth()`         | Detect incorrect color depth flag                                        |⚠️|
|    9 | `Scene::run()`                         | Key events working                                                       |✅|
|   10 | `SceneCom::next()`                     | Calling `close->next()` from within an event                             |⚠️|
|   11 | `GenericScene256::solve_map_requirements_main()` | Assert encounter: `Map base exceeded`                                    |⚠️|
|   12 | `GenericScene256::solve_map_requirements_main()` | Assert encounter: `Backgrounds 0,1 cannot be bitmaps`                    |⚠️|
|   13 | `GenericScene256::solve_map_requirements_main()` | Assert encounter: `Main backgrounds data does not fit in allocated VRAM` |⚠️|
|   14 | `GenericScene256::solve_map_requirements_main()` | Check if tile & map bases are computed correctly                         |⚠️|
|   15 | `GenericScene256::solve_map_requirements_sub()`  | Same observations for the sub engine                                     |🔸|
|   16 | `GenericScene256::load_assets()`| Assert encounter: `Palette allocation failed`                                             |⚠️/🔸|
|   17 | `GenericScene256::require_tiledmap_4bpp()` | Checks for invalid data                                                    |⚠️|
|   18 | `GenericScene256::require_tiledmap_8bpp()` | Checks for invalid data                                                    |⚠️|
|   19 | `GenericScene256::require_tiledmap()` | Checks for invalid data                                                         |⚠️|
|   20 | `GenericScene256::require_bitmap(i,i,i)` | Checks for invalid data                                                      |⚠️|
|   21 | `GenericScene256::require_bitmap(i,cAD*)` | Checks for invalid data                                                     |⚠️|
|   22 | `GenericScene256::require_bitmap_16bpp(i,i,i)` | Checks for invalid data                                                |⚠️|
|   23 | `GenericScene256::require_bitmap_16bpp(i,cAD*)` | Checks for invalid data                                               |⚠️|
|   24 | `GenericScene256::validate_bg_size()`           | Allowing individual map sizes: 128, 256, 512, 1024                    |🍦|
|   25 | `GenericScene256::validate_bg_size()`           | Allowing right map size combination                                   |⚠️|
|   26 | `Allocator::reserve()`           | Reserving memory zone                                                                |⚠️|
|   27 | `Allocator::reserve()`           | Prevent overwriting                                                                  |⚠️|
|   28 | `Allocator::reserve()`           | Desired-offset allocation                                                            |⚠️|
|   29 | `Allocator::reserve()`           | Returning null on fail                                                               |⚠️|
|   30 | `Allocator::reserve()`           | Allocate + Deallocate + Reallocate                                                   |⚠️|
|   31 | `Allocator::release()`           | Freeing occupied segment                                                             |⚠️|
|   32 | `Allocator::release()`           | Adjacent segments merging                                                            |⚠️|
|   33 | `Allocator::release()`           | Freeing what resides at the start of the memory zone                                 |⚠️|
|   34 | `Allocator::release()`           | Ignoring invalid addresses                                                           |⚠️|
|   35 | `Measure::*`, `MeasureValue::*`  | Check the math, should be straight forward                                           |✅|
|   36 | `validate_palette_manager_constructor_input()`| Maybe also allow shadow-palettes in WRAM?   |🔸|
|   37 | `free_bit_pos()`| Check the math, should be straight forward                                                            |🍦|
|   38 | `PaletteManager::reserve1()`| Reserve a new color index                                                                 |🍦|
|   39 | `PaletteManager::reserve1()`| Prevents color duplicates                                                                 |🍦|
|   40 | `PaletteManager::reserve1()`| Returns -1 on fail                                                                        |🍦|
|   41 | `PaletteManager::unload1()` | Removes colors allocated one                                                              |🍦|
|   42 | `PaletteManager::unload1()` | Keeps colors still in use                                                                 |🍦|
|   43 | `PaletteManager::unload1()` | Ignores inexistent colors                                                                 |🍦|
|   44 | `PaletteManager::reserve16()` | Reserves a new slot                                                                     |🍦|
|   45 | `PaletteManager::reserve16()` | Prevents duplicates                                                                     |🍦|
|   46 | `PaletteManager::reserve16()` | Returns -1 on fail                                                                      |🍦|
|   47 | `PaletteManager::unload()`    | Removes palettes allocated once                                                         |🍦|
|   48 | `PaletteManager::unload()`    | Keeps palettes still in use                                                             |🍦|
|   49 | `PaletteManager::unload()`    | Ignores inexistent palettes                                                             |🍦|
|   50 | `PaletteManager::try_load()`  | Error on 16-bit asset                                                                   |⚠️|
|   51 | `PaletteManager::try_load()`  | Loads 4-bit asset                                                                       |⚠️|
|   52 | `PaletteManager::try_load()`  | Loads 8-bit asset                                                                       |🍦|
|   53 | `PaletteManager::unload()`    | Error on 16-bit asset                                                                   |⚠️|
|   54 | `PaletteManager::unload()`    | Loads 4-bit asset                                                                       |⚠️|
|   55 | `PaletteManager::unload()`    | Loads 8-bit asset                                                                       |🍦|
|   56 | `VramLoader::load()`          | Copies without additional buffer (4bpp, 16bpp and 8bpp w/o) dynamic indices             |⚠️|
|   57 | `VramLoader::load()`          | Copies with additional buffer 8bpp w/ dynamic palette indices                           |🍦|
|   58 | `Vector::*`          | Check Vector functionalities                          |✅|
|   59 | `HashMap::*`         | Check HashMap functionalities                          |✅|
|   59 | `Stack::*`         | Check Stack functionalities                          |✅|
|   59 | `BitsArray::*`         | Check BitsArray functionalities                          |✅|
