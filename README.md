# game_engine
personal project game engine with siplest physic. made in C++. graphics with SDL2. build with CMake.

to use this project you need sdl2 and sdl2_image installed! on pacman use this
```
sudo pacman -S sdl2_image  
sudo pacman -S sdl2
```

to build project by your own:
```
cmake -S. -Bbuild
cmake --build build
```

to launch tests, enter following command

```
ctest --verbose --test-dir build  
```

to launch app write

```
./build/platformer
```
