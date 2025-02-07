#include "../include/Obstaculos/Plataforma.h"

namespace Entidades{
namespace Obstaculos{
Plataforma :: Plataforma(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Obstaculo(pos,tam,ID)
{
            //  pSprite->setColor(sf::Color::Blue);
            
            //  printf("POSIÇÃO EM X DA PLATAFORMA: %.1f\n",pos.x);

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
        //  printf("ANTES em Y: %1.f\n", posicao.y);
        //    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getLocalBounds().height / 2);
        //    pSprite->setPosition(sf::Vector2f(posicao.x + pSprite->getOrigin().x, -10+posicao.y + pSprite->getOrigin().y));
        
        
            // printf("DEPOIS em Y: %1.f\n", pSprite->getPosition().y);
            pGG->desenhar(pSprite); //será que dá o this?
    }
    else{
        throw std::runtime_error("o Sprite da plataforma estava vazio");
    }
    }


void Plataforma :: salvar(){}

void Plataforma::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}
}
}