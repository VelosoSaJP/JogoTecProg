# CMake generated Testfile for 
# Source directory: /home/joao/Documents/TecProg/JOGO/JogoTecProg
# Build directory: /home/joao/Documents/TecProg/JOGO/JogoTecProg/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[SFML_MainTest]=] "/home/joao/Documents/TecProg/JOGO/JogoTecProg/bin/mainteste")
set_tests_properties([=[SFML_MainTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/joao/Documents/TecProg/JOGO/JogoTecProg/CMakeLists.txt;64;add_test;/home/joao/Documents/TecProg/JOGO/JogoTecProg/CMakeLists.txt;0;")
subdirs("_deps/sfml-build")
subdirs("src")
