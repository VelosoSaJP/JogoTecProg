#include "../include/Entidade.h"
namespace Entidades{

Entidade:: Entidade(){

}
Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam):
    Ente(pos,tam,velocidade)
{
}

Entidade:: ~Entidade(){

}
void Entidade::salvarDataBuffer(){
    
}
const sf::Vector2f Entidade::getPosicao() /*const*/{
    //return pSprite.vec();}
    if(posicao.x > WIDTH){
        posicao.x = WIDTH*0.9;
        printf("\nENTROU");

    }
    if(posicao.y > HEIGTH){
        posicao.y = HEIGTH;
    }                printf("\nX: %f",posicao.x);


    return posicao;
}
}