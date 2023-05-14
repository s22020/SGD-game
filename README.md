# SGD Kapibara game
#### Instruction for Windows with CLion setup and Visual Studio
1. Clone a repository
2. Download SDL devel for Visual Studio: https://github.com/libsdl-org/SDL/releases and https://github.com/libsdl-org/SDL_image/releases and unpack wherever you like. Alternatively, unzip SDL2-2.26.5.zip added to repo
3. Change environment variables of lib and include directories in CMakeLists.txt to location of unpacked libraries from step 2
4. Add `lib` folder's DLLs to the location of executables (f.i. in CLion it would be cmake-debug-build")
5. CMakeLists-pracownia.txt is there only to run in university labs. If you run a project in labs, rename CMakeLists.txt to CMakeLists-old.txt and rename CMakeLists-pracownia.txt to CMakeLists.txt. If you run it like this, the content of SDL_image repo must be added to the location where the SDL libraries are 
6. Run a project



#### Instruction for development from scratch (Debian/Ubuntu - will be improved later)
sudo apt-get update && sudo apt-get install libsdl2-dev


Background image was created by Szadi art: https://szadiart.itch.io/background-desert-mountains
