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
    
}
void Arvore::salvar(){
    
} 

void Arvore::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

}
}