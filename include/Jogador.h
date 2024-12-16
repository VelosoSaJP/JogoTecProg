#include "Personagem.h"
#pragma once

namespace Personagens{
class Jogador : public Personagem{
private:
    int pontos;
public:
    Jogador();
    ~Jogador();
    void executar();
};
}
//lembrar que herda mover de personagem.