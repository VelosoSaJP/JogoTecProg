#include "../include/Personagens/Mago.h"
namespace Entidades{
namespace Personagens{

Mago :: Mago(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Inimigo(pos,tam,idMAGO),
    vida(1000){
}

Mago :: Mago(){

}

Mago :: ~Mago(){

}

void Mago :: executar(){
    desenhar();
}

void Mago:: desenhar(){
    if (pSprite){
        pGG->desenhar(pSprite); //será que dá o this?
    }
    else{
        throw std::runtime_error("o Sprite do mago estava vazio");
    }
}


void Mago :: danificar(Jogador* p){
     
}
void Mago :: salvar(){
    
}
void Mago::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

}
}