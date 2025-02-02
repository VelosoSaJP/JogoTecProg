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

    void Jogador::saltar(){

    }
        
    void Jogador:: executar(){
       setPosicao (velocidade*pGG->getDeltaTime());
    }

    bool Jogador::ehInimigo(){
        return false;
    }

    void Entidades::Personagens::Jogador::andar(bool direita){

        if (direita){
            velocidade.x = pGG->getDeltaTime() *0.75;
            if (pSprite->getPosition().x < 752) {
                pSprite -> move(velocidade.x,velocidade.y );
                if(pSprite->getScale().x < 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }
            else{
                pSprite->setPosition(getPosicao());
            }
        }
        else{
            //corpo.move(-getVel().x,0.0f);
            velocidade.x = -pGG->getDeltaTime() * 0.75;
            if(pSprite->getPosition().x>0){
                pSprite -> move(velocidade.x,velocidade.y );
                if(pSprite->getScale().x > 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }
            else{
                pSprite->setPosition(getPosicao());
            }
        }
   
    }
        void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}
        //FALTA IMPLEMENTAR AINDA ^

    
    void Jogador :: salvar(){}
}
}