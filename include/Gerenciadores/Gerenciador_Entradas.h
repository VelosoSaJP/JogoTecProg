#pragma once
#include <SFML/Graphics.hpp>
#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include "../Personagens/Jogador.h"
//#include "Gerenciador_Estado.h"
#include "../../include/Estado/Estado.h"

namespace Gerenciador{
    class GerenciadorEstado;
}

namespace Gerenciadores{
class Gerenciador_Entradas{
private:
    
    static Gerenciador_Entradas* instancia;
    static Gerenciador_Grafico* pGG;
    Entidades::Personagens::Jogador* pJog1;
    Entidades::Personagens::Jogador* pJog2;

    Gerenciador::GerenciadorEstado* pGEstado;
    bool ehDois;
    

private:
    Gerenciador_Entradas();

public:
    ~Gerenciador_Entradas();
    static Gerenciador_Entradas* getInstancia() ;
    void teclaApertada(sf::Keyboard::Key tecla);
    void teclaLiberada(sf::Keyboard::Key tecla);
    void setJogador1(Entidades::Personagens::Jogador* pJog);
    void setJogador2(Entidades::Personagens::Jogador* pJog);
    void setEhDois(bool mudaJOG);
    bool getEhDois();

};
}