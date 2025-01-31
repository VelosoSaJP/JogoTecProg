#include "../include/Personagens/Inimigo.h"


namespace Entidades{
namespace Personagens{
    Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam):
        Personagem(pos,tam),
        nivel_maldade(0)    
    {

    }
    
    Inimigo:: Inimigo(){

    }
    Inimigo:: ~Inimigo(){

    }
    void Inimigo::mover(){

    }

}
}