#pragma once
#include "Gerenciadores/Gerenciador_Grafico.h"
// #include "manager/Gerenciador_Eventos.h"
// #include "ListaEntidade.h"
#include "Fases/Floresta.h"
#include "Fases/Lava.h"

#include "Gerenciadores/Gerenciador_Estado.h"
#include "Estado/EstadoJogar.h"

class Jogo{
private:
    /*por padrão, no c++, eu só posso usar ponteiro em uma classe pré declarada.Como dei include, ela não está pre declarada,
    entretanto, mesmo assim é melhor usar ponteiro nessa situação.*/
    Gerenciadores:: Gerenciador_Grafico* pGG;
    Gerenciadores:: Gerenciador_Eventos* pGE;
    // Lista::ListaEntidade* pLE;
    Gerenciador::GerenciadorEstado* pGEstado; 
    Estado::EstadoJogar* pEstadoJogar;
public:
    Jogo();
    ~Jogo();
    void executar();
};