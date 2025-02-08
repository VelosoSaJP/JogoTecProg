#include "../include/Personagens/Orc.h"
namespace Entidades{
namespace Personagens{
Orc :: Orc(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Inimigo(pos,tam,idORC),
    vida(300){
}

Orc :: Orc(){

}

Orc :: ~Orc(){

}

void Orc :: executar(){
    desenhar();
    empuxo();
}
void Orc :: desenhar(){
    if (pSprite){
        pGG->desenhar(pSprite); //será que dá o this?
    }
    else{
        throw std::runtime_error("o Sprite do Orc estava vazio");
    }
}
void Orc :: danificar(Jogador* p){
     
}
void Orc :: salvar(){
    
}
void Orc::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Orc::empuxo(){
    gravidade=0;
    velocidade.y=0;
}
}
}