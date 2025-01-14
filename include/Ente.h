#pragma once
#include <iostream>
// #include "manager/Gerenciador_Grafico.h"
//  #include "manager/Gerenciador_Eventos.h"
#include "manager/Gerenciador_Grafico.h"

using namespace std;

class Ente{
protected:
    int id;
    static int cont;
    sf::Vector2f tamanho;
    sf ::Vector2f posicao;
    sf ::Vector2f velocidade;

    static Gerenciadores ::  Gerenciador_Grafico*  pGG;
    // static Gerenciadores :: Gerenciador_Eventos*  pGE; acho que não será necessário.

    sf::Sprite* pSprite; //equivalente ao Figura*
    sf::Texture* pText;
   
public:
Ente(); //construtora vazia
Ente(sf::Vector2f pos, sf::Vector2f tam, sf ::Vector2f velocidade);
~Ente();
void atualizar();

virtual void executar () = 0;


void desenhar();
void setTextura(const char* caminhoTextura);
void setSprite();

void setPosicao(sf::Vector2f pos);

const sf::Vector2f getVel() const;


};