# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joao/Documents/TecProg/JOGO/JogoTecProg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joao/Documents/TecProg/JOGO/JogoTecProg/build

# Include any dependencies generated for this target.
include CMakeFiles/mainteste.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mainteste.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mainteste.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainteste.dir/flags.make

CMakeFiles/mainteste.dir/src/mainteste.cpp.o: CMakeFiles/mainteste.dir/flags.make
CMakeFiles/mainteste.dir/src/mainteste.cpp.o: ../src/mainteste.cpp
CMakeFiles/mainteste.dir/src/mainteste.cpp.o: CMakeFiles/mainteste.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Documents/TecProg/JOGO/JogoTecProg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainteste.dir/src/mainteste.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mainteste.dir/src/mainteste.cpp.o -MF CMakeFiles/mainteste.dir/src/mainteste.cpp.o.d -o CMakeFiles/mainteste.dir/src/mainteste.cpp.o -c /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp

CMakeFiles/mainteste.dir/src/mainteste.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainteste.dir/src/mainteste.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp > CMakeFiles/mainteste.dir/src/mainteste.cpp.i

CMakeFiles/mainteste.dir/src/mainteste.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainteste.dir/src/mainteste.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp -o CMakeFiles/mainteste.dir/src/mainteste.cpp.s

# Object files for target mainteste
mainteste_OBJECTS = \
"CMakeFiles/mainteste.dir/src/mainteste.cpp.o"

# External object files for target mainteste
mainteste_EXTERNAL_OBJECTS =

../bin/mainteste: CMakeFiles/mainteste.dir/src/mainteste.cpp.o
../bin/mainteste: CMakeFiles/mainteste.dir/build.make
../bin/mainteste: _deps/sfml-build/lib/libsfml-graphics.a
../bin/mainteste: _deps/sfml-build/lib/libsfml-window.a
../bin/mainteste: _deps/sfml-build/lib/libsfml-system.a
../bin/mainteste: _deps/sfml-build/lib/libsfml-audio.a
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libXrandr.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libXcursor.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libudev.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libfreetype.so
../bin/mainteste: _deps/sfml-build/lib/libsfml-system.a
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libopenal.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libvorbis.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libogg.so
../bin/mainteste: /usr/lib/x86_64-linux-gnu/libFLAC.so
../bin/mainteste: CMakeFiles/mainteste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joao/Documents/TecProg/JOGO/JogoTecProg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/mainteste"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainteste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainteste.dir/build: ../bin/mainteste
.PHONY : CMakeFiles/mainteste.dir/build

CMakeFiles/mainteste.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainteste.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainteste.dir/clean

CMakeFiles/mainteste.dir/depend:
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joao/Documents/TecProg/JOGO/JogoTecProg /home/joao/Documents/TecProg/JOGO/JogoTecProg /home/joao/Documents/TecProg/JOGO/JogoTecProg/build /home/joao/Documents/TecProg/JOGO/JogoTecProg/build /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/CMakeFiles/mainteste.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainteste.dir/depend

