#include "../include/Obstaculos/Fogo.h"


namespace Entidades{
namespace Obstaculos{
Fogo :: Fogo(sf::Vector2f pos, sf::Vector2f tam,int ID):
    Obstaculo(pos,tam,idFOGO),
    danar(300)
{
    empuxo();
}
Fogo :: Fogo(){
    
}
Fogo :: ~Fogo(){
    
}

void Fogo::executar(){
    desenhar();
}

void Fogo::desenhar(){
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
        }}
void Fogo::salvar(){
    
} 

void Fogo::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Fogo::empuxo(){
    gravidade=0;
}

void Fogo::obstacular(Personagens::Jogador* p){
    if(p){
        p->tomarDano(danar);
    }
    else{
        printf("Ponteiro nulo de jogador dentro de fogo\n");
    }
}

}
}