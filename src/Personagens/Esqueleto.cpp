#include "../include/Personagens/Esqueleto.h"
namespace Entidades{
namespace Personagens{

Esqueleto :: Esqueleto(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Inimigo(pos,tam,idESQUELETO),
    vida(100)
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
        // sf::Vector2f tam_original=getTamanho();
        pGG->desenhar(pSprite); //será que dá o this?
        // setTamanho(sf::Vector2f(16,16));
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