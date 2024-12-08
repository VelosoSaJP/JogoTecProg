#pragma once
#include "../manager/GraphicsManager.h"
#include "Jogador.h"

class Jogo{
private:
    /*por padrão, no c++, eu só posso usar ponteiro em uma classe pré declarada.Como dei include, ela não está pre declarada,
    entretanto, mesmo assim é melhor usar ponteiro nessa situação.*/
    Personagens:: Jogador* pjog1; 
    Gerenciadores:: GraphicsManager GG;

public:
    Jogo();
    ~Jogo();
    void executar();
};