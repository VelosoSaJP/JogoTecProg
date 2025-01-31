#pragma once
#include "manager/Gerenciador_Grafico.h"
// #include "manager/Gerenciador_Eventos.h"
// #include "ListaEntidade.h"
#include "Fases/Floresta.h"
#include "Fases/Lava.h"

class Jogo{
private:
    /*por padrão, no c++, eu só posso usar ponteiro em uma classe pré declarada.Como dei include, ela não está pre declarada,
    entretanto, mesmo assim é melhor usar ponteiro nessa situação.*/
    Gerenciadores:: Gerenciador_Grafico* pGG;
    // Gerenciadores:: Gerenciador_Eventos* pGE;
    // Lista::ListaEntidade* pLE;


public:
    Jogo();
    ~Jogo();
    void executar();
};