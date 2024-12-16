#include "Entidade.h"
#pragma once

namespace Personagens {
class Personagem : public Entidades :: Entidade{
protected:
    int num_vidas;
public:
    Personagem();
    ~Personagem();
    void salvarDataBuffer();
    virtual void mover();
    virtual void executar()=0;
};
}