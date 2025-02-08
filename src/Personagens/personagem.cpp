#include "../include/Personagens/Personagem.h"
namespace Entidades{
namespace Personagens{
    Personagem::Personagem(){

    }
    Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, int ID):
        Entidade(pos,tam, ID),
        num_vidas(0)

    {
        hitbox();
        
    }
    Personagem::~Personagem(){
        
    }      

    int const Personagem::getVidas(){
        return num_vidas;
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

bool Personagem::getPodeSaltar(){}
void Personagem::setPodeSaltar(bool permissao){}
void Personagem::empuxo(){}
}}