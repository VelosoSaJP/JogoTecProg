#include "../include/Personagens/Mago.h"
namespace Entidades{
namespace Personagens{

Mago :: Mago(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida,int dano):
    Inimigo(pos,tam,idMAGO,vida, dano)
{   
   
}

Mago :: Mago(){

}

Mago :: ~Mago(){

}

void Mago :: executar(){
    desenhar();
    empuxo();
}

void Mago:: desenhar(){
    if (pSprite){
        pGG->desenhar(pSprite);
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

void Mago::empuxo(){
    gravidade=0;
    velocidade.y=0;
}

}
}