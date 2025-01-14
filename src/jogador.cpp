#include "../include/Jogador.h"

namespace Entidades{
namespace Personagens{
    Jogador::Jogador(){

    }
    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
        pontos(0),
        Personagem(pos,tam) 
    {
        setTextura("../assets/Bonecos/Jogador1/guerreiro.png");
    }

    Jogador:: ~Jogador(){

    }
    void   Jogador:: executar(){
        mover();
       setPosicao (velocidade*pGG->getDeltaTime());
    }
    void Jogador :: salvar(){

    }

    void Entidades::Personagens::Jogador::mover(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //corpo.move(-getVel().x,0.0f);
            velocidade.x -= pGG->getDeltaTime() * 0.01;
            pSprite->setPosition(getPosicao());

        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //corpo.move(getVel().x,0.0f);
            velocidade.x += pGG->getDeltaTime() * 0.01;
            pSprite->setPosition(getPosicao());

        }
        //para o w vai ser diferente, pq é um pulo
    }
}
}