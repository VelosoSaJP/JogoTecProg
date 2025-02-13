#include "../include/Obstaculos/Plataforma.h"

namespace Entidades{
namespace Obstaculos{
Plataforma :: Plataforma(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Obstaculo(pos,tam,ID),
    venenosa(1)
{
    empuxo();

}
Plataforma :: Plataforma(){
}
Plataforma :: ~Plataforma(){
    
}
void Plataforma :: executar(){
    desenhar();
}

void Plataforma :: desenhar(){

    if(pSprite){
        sf::RectangleShape desenhaColisao;
            desenhaColisao.setFillColor(sf::Color::Transparent);
            desenhaColisao.setOutlineColor(sf::Color::Yellow);
            sf::Vector2f posicaoColisao;
            sf::Vector2f tamanhoColisao;
        
            posicaoColisao={pSprite->getGlobalBounds().left,pSprite->getGlobalBounds().top};
            tamanhoColisao={pSprite->getGlobalBounds().width,pSprite->getGlobalBounds().height};
            desenhaColisao.setSize(tamanhoColisao);
            desenhaColisao.setPosition(posicaoColisao);

            desenhaColisao.setOutlineThickness(1.f);
            


            pGG->desenhar(pSprite);
            pGG->desenhar(desenhaColisao);
    }
    else{
        throw std::runtime_error("o Sprite da plataforma estava vazio");
    }
    }


void Plataforma :: salvar(){}

void Plataforma::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Plataforma::empuxo(){
    gravidade=0;
}

void Plataforma::obstacular(Personagens::Jogador* p){
    if(p){
        p->tomarDano(p->getVida()*venenosa);
    }
    else{
        printf("Ponteiro falso em obstacular de  plataforma");
    }

}
}
}