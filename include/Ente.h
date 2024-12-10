#pragma once
#include <iostream>
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
using namespace std;

class Ente{
protected:
    int id;
    sf::Vector2f tam;
    sf ::Vector2f pos;
    
    static int cont;
    static Gerenciadores ::  Gerenciador_Grafico*  pGG;
    static Gerenciadores :: Gerenciador_Eventos*  pGE;

    sf::Sprite* pFig; //equivalente ao Figura*

public:
Ente();
~Ente();
virtual void executar () = 0;
void desenhar();

};

