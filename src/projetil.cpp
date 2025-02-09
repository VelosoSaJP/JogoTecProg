#include "../include/Projetil.h"

namespace Entidades{

Projetil :: Projetil(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Entidade(pos,tam,idPROJETIL),
    dano(100)
{
    
}
Projetil :: Projetil(){
    
}
Projetil :: ~Projetil(){
    
}
void Projetil :: executar(){
    arremesado();
    desenhar();
}
void Projetil :: desenhar(){
    if(pSprite){
        pGG->desenhar(pSprite);
    }
}
void Projetil :: colisao(Entidade* outraEntidade,sf::Vector2f distancia){

}
void Projetil :: salvar(){

} 

void Projetil :: arremesado(){
        float limite_mov=80-pSprite->getGlobalBounds().width/2;
         
         
            velocidade.x = pGG->getDeltaTime() *0.01;
            pSprite -> move(velocidade.x,velocidade.y );
       
  
}

}