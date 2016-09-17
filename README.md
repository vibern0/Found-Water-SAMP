# Found-Water-SAMP
[![License][license-svg]][license-url]

A C++ plugin for SA-MP to check when player is in water.

##How to build in Visual Studio
####1. Create the project
- Open Visual Studio
- In "File -> New -> Project" select "Win32 Project", give a name and click "next"
- At the next window click "next"
- Next windows in "Aplication type" choose "DLL"
- In "Additional option" remove all selections and select only "Empty Project"
- Click "Finish"

####2. Add files
- Add everything to Visual Studio project, including the SDK folder

####3. Configure the project
- Move the file "main.def" to the project folder root.
- Open project properties window (by clicking with the right mouse button in the project in Visual Studio)
- Go "Linker -> Input"
- At "Module Definition File" write "main.def"
- Save and compile

##This repo contains
This repository contains the plugin and two pawn script.
One script to help the administrator creating the areas and another one has a example using water areas.

##Plugin functions
```c++
int add_water_area(char* area);
bool remove_water_area(int id);
bool point_in_any_water_area(int x, int y);
```

##Built with
The area system (the plugin) is written in C++ and uses the [boost][boost-url] library.

[boost-url]: http://www.boost.org/
[license-svg]: https://img.shields.io/badge/license-GNU%20v.3-blue.svg
[license-url]: https://github.com/obernardovieira/Found-Water-SAMP
