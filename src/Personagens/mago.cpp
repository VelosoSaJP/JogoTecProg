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

}
void Mago :: danificar(Jogador* p){
     
}
void Mago :: salvar(){
    
}
void Mago::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

}
}