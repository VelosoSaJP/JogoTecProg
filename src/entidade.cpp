#include "../include/Entidade.h"
namespace Entidades{

Entidade:: Entidade(){

}
Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Ente(pos,tam,velocidade, ID),
    gravidade(0.0001f),
    altura_pulo(0.5f)
{
}

Entidade:: ~Entidade(){


}
void Entidade::efeitoGravidade(){
    // std::cout << "Posição do jogador: " << pSprite->getPosition().x << ", " << pSprite->getPosition().y << std::endl;
        
        // velocidade.y=  sqrtf(0.0005f * gravidade * altura_pulo);
        velocidade.y += gravidade*pGG->getDeltaTime();
        pSprite -> move(velocidade.x,velocidade.y );
    

}   
void Entidade::  andar(bool direita){

}

const sf::Vector2f Entidade::getOrigem(){
    return pSprite->getOrigin();
}

const sf::Vector2f Entidade::getPosicaoEstatica(){
     return posicao;
}
const sf::Vector2f Entidade::getPosicaoMovel(){
/*
    if(posicao.x > WIDTH){
         posicao.x = WIDTH*0.93;

    }
    else if(posicao.x<0){
        posicao.x=WIDTH*0.03;
    }

    if(posicao.y > HEIGTH){
        posicao.y = 10;
    }     
    else if( posicao.y<0){
        posicao.y=HEIGTH*0.03;
    }        
*/
    return pSprite->getPosition();
}
}