#include "../include/Obstaculos/Arvore.h"
namespace Entidades{
namespace Obstaculos{
    Arvore::Arvore(sf::Vector2f pos, sf::Vector2f tam,int ID):
        Obstaculo(pos,tam, ID)
    {

    }
    Arvore::Arvore(){}
    Arvore:: ~Arvore(){

    }

void Arvore::executar(){
    desenhar();
}
void Arvore::salvar(){
    
} 
void Arvore::desenhar(){
    if (pSprite){
            setTamanho(sf::Vector2f(0.1,0.1));
            pGG->desenhar(pSprite); //será que dá o this?
            setTamanho(sf::Vector2f(16,16));
        }
}
void Arvore::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

}
}