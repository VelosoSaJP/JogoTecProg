cmake_minimum_required(VERSION 3.22)
project(JogoTecProg LANGUAGES CXX)

# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include_directories(include)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/**/*.cpp")

add_executable(${PROJECT_NAME}  ${SOURCES})

# Adiciona todas as bibliotecas necessárias da SFML
target_link_libraries(JogoTecProg PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)

# Configura a versão do C++ (você já está fazendo isso corretamente)
target_compile_features(JogoTecProg PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET JogoTecProg
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()