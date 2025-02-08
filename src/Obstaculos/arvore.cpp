#include "../include/Obstaculos/Arvore.h"
namespace Entidades{
namespace Obstaculos{
    Arvore::Arvore(sf::Vector2f pos, sf::Vector2f tam,int ID):
        Obstaculo(pos,tam, ID)
    {
        empuxo();
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
             sf::RectangleShape desenhaColisao;
            desenhaColisao.setFillColor(sf::Color::Transparent);
            desenhaColisao.setOutlineColor(sf::Color::Magenta);
            sf::Vector2f posicaoColisao;
            sf::Vector2f tamanhoColisao;
        
            posicaoColisao={pSprite->getGlobalBounds().left,pSprite->getGlobalBounds().top};
            tamanhoColisao={pSprite->getGlobalBounds().width,pSprite->getGlobalBounds().height};
            desenhaColisao.setSize(tamanhoColisao);
            desenhaColisao.setPosition(posicaoColisao);

            desenhaColisao.setOutlineThickness(1.f);

            pGG->desenhar(pSprite); //será que dá o this?
            pGG->desenhar(desenhaColisao);
        }
}
void Arvore::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Arvore::empuxo(){
    gravidade=0;
}

}
}