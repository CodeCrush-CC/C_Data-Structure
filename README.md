# Data-Structures and Algorithms using-C/C++

## Download MS-DosBox version-0.74 for Windows [here](https://drive.google.com/open?id=1ptV06g5P5zt3ryw1uI5zrxxg3TeMQCxA)

**Instructions:** 

- Unzip the file.
- Paste the DOSBox_TurboC++ forlder in your C:\ drive and rename it as TurboC++.
- Go to C:\TurboC++\TurboC++ and there you will find DOSBox of *type- Application* create the shortcut for this on your desktop.
- Run `DOSBox`.
- It may automatically detect the path for bin folder
  OR 
- You have to do it manually. By changing drive from Z:\ to C:\ using cd command and then cd C:\TurboC++\Disk\TurboC3\BIN

## Download Visual Studio Code for Windows [here](https://code.visualstudio.com/)

**Instructions:**

- Run the `VSCodeUserSetup.exe` and install the VSCode on your system.
- For compiling C/C++ programs `INSTALL MinGW` compiler from [here](https://drive.google.com/file/d/1Hf33gIef6qCAtTZRlx9f-nL8fpnS4qdG/view?usp=sharing)
- Run `mingw-get-setup.exe`, Check on all the packages and click on install. It may take some time.
- Edit the system environment variables by pressing window button and search for `Edit the system environment variables`.
  - Click on Environment variables.
  - Select `Path` for system variables.
  - Click on Edit. 
  - Paste this path: _C:\MinGW\bin_.
- Open the VSCode.
  - Click on _Extensions_.
  - Search for _C/C++ IntelliSense_.
  - Click on _Install_.
- Create new file and save it with extension .cpp OR .c
- To compile your programs press Ctrl + Shift + B.
  - Select First option for C programs.
  - Select Second option for C++ programs. 
 - To run the programs 
  - Click on Terminal.
  - Write your program name without extension followed by `./`
  
**Note:** There is a difference between DosBox and MinGW compiler. Programs that are compiled using DosBox may give error with MinGW and vice-versa, but with little bit         modification in the program the error can be resolved.


Enjoy! Happy Coding!
