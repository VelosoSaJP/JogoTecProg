#include "../include/Personagens/Orc.h"
namespace Entidades{
namespace Personagens{
Orc :: Orc(sf::Vector2f pos, sf::Vector2f tam):
    Inimigo(pos,tam),
    vida(300){
}

Orc :: Orc(){

}

Orc :: ~Orc(){

}

void Orc :: executar(){

}
void Orc :: danificar(Jogador* p){
     
}
void Orc :: salvar(){
    
}
void Orc::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

}
}