# ARPG

Instead of using MSVC NMake (Default Visual Studio build system) we're using CMake, a cross platform build solution. This also makes the project portable between almost any IDE under the sun, e.g

- Visual Studio (Any Version)
- CLion (What I'm using)
- Code::Blocks (Don't know why you'd want to use it but you can)
- etc...

Anyhow, since it's not a VS project things work a little differently.

## Visual Studio Instructions:

1. Open Visual Studio (version up to you)
2. Select "Open Folder", not "Open Project/Solution", and navigate to the project folder.
3. Wait while Visual studio generates it's own project files and things (you can see progress in the build console).
4. From the top, change your project architecture (from the dropdown) from x86-Debug to x64-Debug (or x64-Release if you don't want debugging).
5. Drow down the "Select Startup Item..." run button, and select the executable. Thats it, from here on out it behaves like normal Visual Studio.

## Clion Instructions:

I know the likelihood of people needing these is low, but here I go anyway. Unlike VS which uses NMake and a proprietary build system, CLion uses CMake out of the box, that means that it's a lot easier.

1. Open CLion
2. Hit the "Open" button, and pick the folder.
3. Wait for CLion to sort out it's CMake stuff (based on currently configured Toolchain - probably MinGW by default).
4. Thats it.
