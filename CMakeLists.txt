# Define a versão mínima do CMake
cmake_minimum_required(VERSION 3.20)

# Configurações do projeto
project(MeuPrimeiroJogoSohMeu LANGUAGES CXX)

# Ativa testes
enable_testing()

# Inclui o suporte ao CTest
include(CTest)

# Define o padrão C++ e força seu uso
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configura o diretório de saída para binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Configuração para bibliotecas compartilhadas
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Inclui SFML usando FetchContent
include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
)

FetchContent_MakeAvailable(SFML)


# Verifica se SFML foi incluído corretamente
if(NOT TARGET sfml-graphics)
    message(FATAL_ERROR "SFML não foi encontrado ou configurado corretamente")
endif()

# Adiciona o diretório do código-fonte
add_subdirectory(src)

# Adiciona um executável de teste
add_executable(mainteste src/mainteste.cpp)

# Inclui diretórios de cabeçalhos
target_include_directories(mainteste
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Vincula as bibliotecas SFML necessárias ao teste
target_link_libraries(mainteste
  PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
)

# Registra o teste no CTest
add_test(NAME SFML_MainTest COMMAND mainteste)
