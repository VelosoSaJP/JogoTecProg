#pragma once
#include <iostream>
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
using namespace std;

class Ente{
protected:
    int id;
    static int cont;
    sf::Vector2f tamanho;
    sf ::Vector2f posicao;
    
    static Gerenciadores ::  Gerenciador_Grafico*  pGG;
    static Gerenciadores :: Gerenciador_Eventos*  pGE;

    sf::Sprite* pFig; //equivalente ao Figura*

public:
Ente();
~Ente();
virtual void executar () = 0;
void desenhar();

};

