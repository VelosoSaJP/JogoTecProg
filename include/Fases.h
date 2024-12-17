#pragma once
#include "Ente.h"
#include "manager/Gerenciador_Colisoes.h"

namespace Fases{
class Fase : public Ente{
private:
    Gerenciadores::Gerenciador_Colisoes* pGC;

public:
    Fase();
    ~Fase();
    virtual void executar();
    void gerenciarColisoes();
    void criarPlataformas();
    void criarCenario();
    virtual void criarInimigos() = 0;
    virtual void criarObstaculos();


};
}
