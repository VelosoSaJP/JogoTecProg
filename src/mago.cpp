#include "../include/Personagens/Mago.h"
namespace Entidades{
namespace Personagens{

Mago :: Mago(sf::Vector2f pos, sf::Vector2f tam):
    Inimigo(pos,tam),
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

}
}