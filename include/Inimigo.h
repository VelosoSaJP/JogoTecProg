#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Personagens{
class Inimigo : public Personagem{
protected:
    int nivel_maldade;
    
public:
Inimigo();
~Inimigo();
void salvarDataBuffer();
virtual void executar () = 0;
virtual void danificar (Jogador* p);
};
}