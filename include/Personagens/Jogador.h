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
    Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID);
    ~Jogador();
    void executar();
    void salvar();
    void saltar();
    void andar(bool direita);
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);

};

}
}
//lembrar que herda mover de personagem(entidade).