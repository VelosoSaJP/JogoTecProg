#include "../include/Entidade.h"
namespace Entidades{

Entidade:: Entidade(){

}
Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Ente(pos,tam,velocidade, ID)
{
}

Entidade:: ~Entidade(){

}
// void Entidade::salvar(){}
// void Entidade :: executar(){}

const sf::Vector2f Entidade::getPosicao() /*const*/{
    //return pSprite.vec();}
    if(posicao.x > WIDTH){
        posicao.x = WIDTH*0.93;
        // printf("\nENTROU");

    }
    else if(posicao.x<0){
        posicao.x=WIDTH*0.03;
    }

    if(posicao.y > HEIGTH){
        posicao.y = HEIGTH;
    }     
    else if( posicao.y<0){
        posicao.y=HEIGTH*0.03;
    }        
    //    printf("\nX: %f",posicao.x);


    return posicao;
}
}