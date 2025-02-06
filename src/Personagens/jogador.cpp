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

    void Jogador::parar(bool salto){
        if(salto){
            velocidade.y=0;
        }
        else{
            velocidade.x=0;
        }
    }


    void Jogador::saltar(Jogador* pJog){

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
                }

                    pSprite->setPosition(pSprite->getPosition());
                //estava  pSprite->setPosition(pSprite->getPosicao());
         }
            else{
               // velocidade.y += gravidade * pGG->getDeltaTime();
               // pSprite->move(velocidade.x, velocidade.y);  
               printf("Não estava no chão\n");
            }
        }
    }
        
    void Jogador:: executar(){
        // printf("Vel em x: %.f\n",velocidade.x);
        // printf("Vel em y: %.f\n",velocidade.y);
        setPosicao (velocidade*pGG->getDeltaTime(),"Executar");
    //    pSprite->setPosition(velocidade*pGG->getDeltaTime());
    }

    void Entidades::Personagens::Jogador::andar(bool direita){
        velocidade.y=0;
        if (direita){
            velocidade.x = pGG->getDeltaTime() *0.03;
            if (pSprite->getPosition().x < WIDTH) {
                pSprite -> move(velocidade.x,velocidade.y );

                if(pSprite->getScale().x < 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }
 
                // ESSAS 2 LINHAS DE BAIXO FAZEM SUMIR O BONECO DA TELA.
                velocidade.y=0;
                // printf("Velocidades no andar: X: %f e Y: %f\n",velocidade.x,velocidade.y);
                pSprite->setPosition(pSprite->getPosition());
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

                pSprite->setPosition(pSprite->getPosition());
                // pSprite->setPosition(getPosicaoMovel());
                //  pSprite->setPosition(pSprite->getPosition());

        }
        // printf("SPRITE em x: %.0f, em y: %.0f\n",pSprite->getPosition().x,pSprite->getPosition().y);
        // printf("NORMAL em x: %.0f, em y: %.0f\n",getPosicao().x,getPosicao().y);
    }
        void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade,sf::Vector2f distancia){
            int opt = outraEntidade->getID();
            switch (opt)
            {
            case (idOBSTACULO): 
                {
                     if(posicao.x > outraEntidade->getPosicaoEstatica().x){
                            printf("Entrando na colisão horizontal\n");
                    
                         setPosicao(sf::Vector2f(posicao.x+distancia.x,posicao.y),"jogador");
                        // printf("getPos em x: %.0f, em y: %.0f\n",getPosicao().x,getPosicao().y);
                        // printf("setPos em X: %.0f e em Y: %.0f\n",posicao.x+distancia.x,posicao.y);

                    }
                    if(getPosicaoMovel().y > outraEntidade->getPosicaoEstatica().y){
                        // printf("ANTIGA POS: %.0f", getPosicaoMovel().y);
                        printf("Entrando na colisão vertical\n");
                        setPosicao(sf::Vector2f(getPosicaoMovel().x,getPosicaoMovel().y+distancia.y),"jogador");
                        // setPosicao(sf::Vector2f(50,200),"jogador");
                        
                        // printf("NOVA POS: %.0f\n", getPosicaoMovel().y);
                        
                     }
                                      
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