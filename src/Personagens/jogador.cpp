#include "../include/Personagens/Jogador.h"

namespace Entidades{
namespace Personagens{
    Jogador::Jogador(){

    }
    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam):
        pontos(0),
        Personagem(pos,tam) 
    {
        
    }

    Jogador:: ~Jogador(){

    }
        
    void Jogador:: executar(){
        mover();
       setPosicao (velocidade*pGG->getDeltaTime());
    }

    void Entidades::Personagens::Jogador::mover(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            //corpo.move(-getVel().x,0.0f);
            velocidade.x = -pGG->getDeltaTime() * 0.1;
            pSprite->setPosition(getPosicao());
            if(pSprite->getScale().x > 0)
                pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //corpo.move(getVel().x,0.0f);
            velocidade.x = pGG->getDeltaTime() * 0.1;
            pSprite->setPosition(getPosicao());
            if(pSprite->getScale().x < 0)
                pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);

        }
        //para o w vai ser diferente, pq é um pulo
    }
        void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}
        //FALTA IMPLEMENTAR AINDA ^

    
    void Jogador :: salvar(){}
}
}