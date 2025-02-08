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

}