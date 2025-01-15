#pragma once
#include "manager/Gerenciador_Grafico.h"
#include "manager/Gerenciador_Eventos.h"
#include "Jogador.h"
#include "ListaEntidade.h"
#include "Obstaculo.h"

class Jogo{
private:
    /*por padrão, no c++, eu só posso usar ponteiro em uma classe pré declarada.Como dei include, ela não está pre declarada,
    entretanto, mesmo assim é melhor usar ponteiro nessa situação.*/
    Entidades::Personagens::Jogador* pJog1; 
    Gerenciadores:: Gerenciador_Grafico* pGG;
    Gerenciadores:: Gerenciador_Eventos* pGE;
    Entidades::Obstaculos::Obstaculo* pObs;
    Lista::ListaEntidade* pLE; //posso criar sem ser ponteiro também.


public:
    Jogo();
    ~Jogo();
    void executar();
};