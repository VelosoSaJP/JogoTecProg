#include "../include/Personagens/Jogador.h"

namespace Entidades{
namespace Personagens{
    Jogador::Jogador(){

    }
    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID):
        Personagem(pos,tam,idJOGADOR) ,
        pontos(0),
         // altura_pulo(1),
        pGC(Gerenciadores::Gerenciador_Colisoes::getInstancia())
    {
        
    }

    Jogador:: ~Jogador(){

    }

    void Jogador::saltar(Jogador* pJog){
        // printf("VEIO PRA SALTAR\n");

      if(pGC && pJog){
            if(pGC->NoChao(pJog)){ ///checo pSprite na função NoChao
                if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&!sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
                    velocidade.x=0;
                }
                if(pSprite->getPosition().y>0){
                    velocidade.y= - sqrtf(2.0f * gravidade * altura_pulo);
                    velocidade.y*=0.8f; 
                    pSprite -> move(velocidade.x,velocidade.y );
            

                    if(pGG){
                        velocidade.y= gravidade*pGG->getDeltaTime();
                    }
                }
                else{
                    pSprite->setPosition(getPosicao());
                }
                
         }
         else{
            // velocidade.y += gravidade * pGG->getDeltaTime();
            // pSprite->move(velocidade.x, velocidade.y);  
            printf("Não estava no chão\n");
         }


        }
    }
        
    void Jogador:: executar(){
       setPosicao (velocidade*pGG->getDeltaTime());
    }

    void Entidades::Personagens::Jogador::andar(bool direita){
        velocidade.y=0;
        if (direita){
            velocidade.x = pGG->getDeltaTime() *0.3;
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
            velocidade.x = -pGG->getDeltaTime() * 0.3;
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
        void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade,sf::Vector2f distancia){
            
            int opt = outraEntidade->getID();
            switch (opt)
            {
            case (idOBSTACULO): 
                {
                    if(posicao.x > outraEntidade->getPosicao().x)
                        setPosicao(sf::Vector2f(posicao.x+distancia.x,posicao.y));
                }
                break;
            
            case(idESQUELETO): 
                {
                    
                }
            default:
                break;
            }

        }
        //FALTA IMPLEMENTAR AINDA ^

    
    void Jogador :: salvar(){}
}
}