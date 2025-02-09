#include "../include/Personagens/Personagem.h"
namespace Entidades{
namespace Personagens{
    Personagem::Personagem(){

    }
    Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida):
        Entidade(pos,tam, ID),
        num_vidas(vida)

    {
        hitbox();
        
    }
    Personagem::~Personagem(){
        
    }      


     void Personagem::andar(bool direita){}

     void Personagem :: hitbox(){
        desenhaColisao.setFillColor(sf::Color::Transparent);
        desenhaColisao.setOutlineColor(sf::Color::Green);
        sf::Vector2f posicaoColisao;
        sf::Vector2f tamanhoColisao;
      
        tamanhoColisao = { pSprite->getGlobalBounds().width, pSprite->getGlobalBounds().height / 2 };
        posicaoColisao = { pSprite->getGlobalBounds().left, pSprite->getGlobalBounds().top + pSprite->getGlobalBounds().height / 2 };

        tamanhoColisao.x*=0.5;
     
        posicaoColisao.x += (pSprite->getGlobalBounds().width * (1 - 0.6)) / 2;
        desenhaColisao.setSize(tamanhoColisao);
        desenhaColisao.setPosition(posicaoColisao);
        desenhaColisao.setOutlineThickness(1.f);
        pGG->desenhar(desenhaColisao);

     }

void Personagem::tomarDano(int dano_sofrido){
    num_vidas-=dano_sofrido;
}

int  Personagem::getVida(){
    return num_vidas;
}

bool Personagem::checarMorte(){
    if (getVida()<0){
        return true; //TENHO QUE REMOVER AQUI
    }
}

void Personagem::empuxo(){}
}}