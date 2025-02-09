#include "../include/Personagens/Esqueleto.h"
namespace Entidades{
namespace Personagens{

Esqueleto :: Esqueleto(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida, int dano):
    Inimigo(pos,tam,idESQUELETO, vida, dano)
{
}

Esqueleto :: Esqueleto(){

}

Esqueleto :: ~Esqueleto(){

}

void Esqueleto :: executar(){
    desenhar();
    empuxo();
}
void Esqueleto :: desenhar(){
    if (pSprite){
        pGG->desenhar(pSprite); 
    }
    else{
        throw std::runtime_error("o Sprite do esqueleto estava vazio");
    }
}
void Esqueleto :: danificar(Jogador* p){
     
}

void Esqueleto::salvar(){

}
void Esqueleto::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Esqueleto:: empuxo(){
    gravidade=0;
    velocidade.y=0;

}

}
}