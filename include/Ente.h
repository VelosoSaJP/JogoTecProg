#pragma once
#include <iostream>
#include "manager/Gerenciador_Grafico.h"
#include "manager/Gerenciador_Eventos.h"
using namespace std;


class Ente{
protected:
    int id;
    static int cont;
    sf::Vector2f tamanho;
    sf ::Vector2f posicao;
    
    static Gerenciadores::Gerenciador_Grafico*  pGG;
    static Gerenciadores::Gerenciador_Eventos*  pGE;

    sf::Sprite* pSprite; //equivalente ao Figura*
    sf::Texture* pText;
   
public:
Ente();
~Ente();
void atualizar();

virtual void executar () = 0;


void desenhar();
void setTexture();
void setSprite();

};

