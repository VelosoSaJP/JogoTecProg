# ---------------------------------------
# Biblioteca do jogo
add_library(jogo
  #Jogo.cpp
  mainteste.cpp
)

# Inclui os diretórios de cabeçalhos para a biblioteca
target_include_directories(jogo
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Vincula bibliotecas do SFML à biblioteca do jogo
target_link_libraries(jogo
  PUBLIC
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
  menu # Certifique-se de que "menu" foi definido no nível principal
)

# ---------------------------------------
# Executável principal
add_executable(simon mainteste.cpp)

# Inclui os diretórios de cabeçalhos para o executável
target_include_directories(simon
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

# Vincula o executável à biblioteca do jogo
target_link_libraries(simon
  PRIVATE
  jogo
)
