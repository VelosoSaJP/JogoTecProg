#pragma once
#include "Personagem.h"
namespace Entidades{
namespace Personagens{

class Jogador : public Personagem{
private:
    int pontos;
    // 
public:
    Jogador ();
    Jogador(sf::Vector2f pos, sf::Vector2f tam);
    ~Jogador();
    void executar();
    void salvar();
    void mover();
};

}
}
//lembrar que herda mover de personagem(entidade).