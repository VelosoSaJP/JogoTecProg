#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Obstaculos{
class Obstaculo : public Entidades::Entidade{
protected:
bool danoso;

private:
Obstaculo();
~Obstaculo();
virtual void executar()=0;
virtual void obstacular (Personagens :: Jogador* p);

};
}