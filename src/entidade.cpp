#include "../include/Entidade.h"
namespace Entidades{

Entidade:: Entidade(){

}
Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam):
    Ente(pos,tam)
{
}

Entidade:: ~Entidade(){

}
void Entidade::salvarDataBuffer(){
    
}
float Entidade::getPosition(){
    //return pSprite.vec();}
    return 0;
}
}

