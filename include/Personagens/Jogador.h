#pragma once
#include "Personagem.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <math.h>
namespace Entidades{
namespace Personagens{

class Jogador : public Personagem{
private:
    int pontos;
    Gerenciadores::Gerenciador_Colisoes* pGC;
     // float altura_pulo;
   
public:
    Jogador ();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID);
    ~Jogador();
    void executar();
    void salvar();
    void saltar(Jogador* pJog);
    void andar(bool direita);
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);

};

}
}
//lembrar que herda mover de personagem(entidade).