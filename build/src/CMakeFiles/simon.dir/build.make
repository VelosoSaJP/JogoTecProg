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
include src/CMakeFiles/simon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/simon.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/simon.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/simon.dir/flags.make

src/CMakeFiles/simon.dir/mainteste.cpp.o: src/CMakeFiles/simon.dir/flags.make
src/CMakeFiles/simon.dir/mainteste.cpp.o: ../src/mainteste.cpp
src/CMakeFiles/simon.dir/mainteste.cpp.o: src/CMakeFiles/simon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Documents/TecProg/JOGO/JogoTecProg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/simon.dir/mainteste.cpp.o"
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/simon.dir/mainteste.cpp.o -MF CMakeFiles/simon.dir/mainteste.cpp.o.d -o CMakeFiles/simon.dir/mainteste.cpp.o -c /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp

src/CMakeFiles/simon.dir/mainteste.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simon.dir/mainteste.cpp.i"
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp > CMakeFiles/simon.dir/mainteste.cpp.i

src/CMakeFiles/simon.dir/mainteste.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simon.dir/mainteste.cpp.s"
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao/Documents/TecProg/JOGO/JogoTecProg/src/mainteste.cpp -o CMakeFiles/simon.dir/mainteste.cpp.s

# Object files for target simon
simon_OBJECTS = \
"CMakeFiles/simon.dir/mainteste.cpp.o"

# External object files for target simon
simon_EXTERNAL_OBJECTS =

../bin/simon: src/CMakeFiles/simon.dir/mainteste.cpp.o
../bin/simon: src/CMakeFiles/simon.dir/build.make
../bin/simon: src/libjogo.a
../bin/simon: _deps/sfml-build/lib/libsfml-graphics.a
../bin/simon: /usr/lib/x86_64-linux-gnu/libfreetype.so
../bin/simon: _deps/sfml-build/lib/libsfml-window.a
../bin/simon: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libXrandr.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libXcursor.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libudev.so
../bin/simon: _deps/sfml-build/lib/libsfml-audio.a
../bin/simon: _deps/sfml-build/lib/libsfml-system.a
../bin/simon: /usr/lib/x86_64-linux-gnu/libopenal.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libvorbisfile.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libvorbis.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libogg.so
../bin/simon: /usr/lib/x86_64-linux-gnu/libFLAC.so
../bin/simon: src/CMakeFiles/simon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joao/Documents/TecProg/JOGO/JogoTecProg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/simon"
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/simon.dir/build: ../bin/simon
.PHONY : src/CMakeFiles/simon.dir/build

src/CMakeFiles/simon.dir/clean:
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src && $(CMAKE_COMMAND) -P CMakeFiles/simon.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/simon.dir/clean

src/CMakeFiles/simon.dir/depend:
	cd /home/joao/Documents/TecProg/JOGO/JogoTecProg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joao/Documents/TecProg/JOGO/JogoTecProg /home/joao/Documents/TecProg/JOGO/JogoTecProg/src /home/joao/Documents/TecProg/JOGO/JogoTecProg/build /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src /home/joao/Documents/TecProg/JOGO/JogoTecProg/build/src/CMakeFiles/simon.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/simon.dir/depend

