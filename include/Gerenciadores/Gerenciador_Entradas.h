#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "../Personagens/Jogador.h"

namespace Gerenciadores{
class Gerenciador_Entradas{
private:
    
    static Gerenciador_Entradas* instancia;
    static Gerenciador_Grafico* pGG;
    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;
    

private:
Gerenciador_Entradas();
public:
~Gerenciador_Entradas();
static Gerenciador_Entradas* getInstancia() ;
void teclaApertada(sf::Keyboard::Key tecla);
void teclaLiberada(sf::Keyboard::Key tecla);
void setJogador1(Entidades::Personagens::Jogador* pJog);
void setJogador2(Entidades::Personagens::Jogador* pJog);

};
}