#include "../include/Obstaculos/Pedra.h"

namespace Entidades{
namespace Obstaculos{
Pedra :: Pedra(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Obstaculo(pos,tam,ID)
{
    executar();
}
Pedra :: Pedra(){
    
}
Pedra :: ~Pedra(){
    
}

void Pedra::executar(){
    desenhar();
}
void Pedra::salvar(){
    
} 

void Pedra::desenhar(){
     if(pSprite){
      
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
                
                //  printf("POS: x= %.1f e y= %.1f\n",desenhaColisao.getPosition().x,desenhaColisao.getPosition().y);
                //  printf("TAM: x= %.1f e y= %.1f\n",desenhaColisao.getSize().x,desenhaColisao.getSize().y);


                pGG->desenhar(pSprite);

                pGG->desenhar(desenhaColisao);
        }
}

void Pedra::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Pedra::empuxo(){
    gravidade=0;
}
}
}