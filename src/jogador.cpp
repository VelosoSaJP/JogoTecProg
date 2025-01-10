#include "../include/Jogador.h"

namespace Entidades{
namespace Personagens{
    Jogador::Jogador(){

    }
    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
        pontos(0),
        Personagem(pos,tam) 
    {
        //setTextura("../assets/Bonecos/Mago/mago.png");
        setTextura("../assets/Bonecos/Esqueleto/esqueleto.png");
    }

    Jogador:: ~Jogador(){

    }
    void   Jogador:: executar(){
        
    }
    void Jogador :: salvar(){

    }
}
}