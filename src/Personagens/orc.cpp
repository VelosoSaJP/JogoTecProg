#include "../include/Personagens/Orc.h"
namespace Entidades{
namespace Personagens{
Orc :: Orc(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida,int dano):
    Inimigo(pos,tam,idORC, vida, dano)
{
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
    if(p){
         p->tomarDano(getVida()-facada);
    }
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