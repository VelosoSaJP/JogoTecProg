#include "../include/Personagens/Jogador.h"

namespace Entidades{
namespace Personagens{
    Jogador::Jogador()
    {

    }

    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID):
        Personagem(sf::Vector2f(pos.x, pos.y),tam,idJOGADOR) ,
        pontos(0),
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


    void Jogador::saltar(){
      if(pGC){
        
            if(1){
                    velocidade.y= - sqrtf(gravidade * altura_pulo);
                    velocidade.y*=10;                  
         }
            else{
               printf("Não estava no chão\n");
            }
        }
    }
        
    void Jogador:: executar(){
        atualizaPosicao();
        desenhar();
    }

    void Jogador :: desenhar(){
         
        if (pSprite){
            setTamanho(sf::Vector2f(0.1,0.1));
            pGG->desenhar(pSprite); //será que dá o this?
            setTamanho(sf::Vector2f(16,16));
        }
        else{
            throw std::runtime_error("o Sprite do jogador estava vazio");
        }
    }

    void Jogador:: atualizaPosicao(){
       pSprite->move(velocidade.x, velocidade.y);
//ANTES ESTAVA SÓ COM O move
// Agora, se você quiser acessar a posição para qualquer outra razão, você pode fazer assim:
    sf::Vector2f novaPosicao = pSprite->getPosition();

    // Se você quiser reposicionar o sprite para uma nova posição (absoluta)
    
    setPosicao(novaPosicao);


    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getLocalBounds().height / 2);


    }

    void Jogador::andar(bool direita){
        velocidade.y=0;
     
        if (direita){
            velocidade.x = pGG->getDeltaTime() *0.03;
            
            if (this->getPosicao().x < WIDTH) {
                // pSprite -> move(velocidade.x,velocidade.y );

                if(pSprite->getScale().x < 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }

                // ESSAS 2 LINHAS DE BAIXO FAZEM SUMIR O BONECO DA TELA.
                velocidade.y=0;
                // this->setPosicao(this->getPosicao());
        }
        else{
            velocidade.x = -pGG->getDeltaTime() *0.03;
            if(this->getPosicao().x>0){
                // pSprite -> move(velocidade.x,velocidade.y );

                if(pSprite->getScale().x > 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }


        }
    }
        void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade,sf::Vector2f distancia){
            int opt = outraEntidade->getID();
            switch (opt)
            {
            case (idOBSTACULO): 
                {
                     if(posicao.x > outraEntidade->getPosicao().x){
                        //    setPosicao(sf::Vector2f(posicao.x+distancia.x,getPosicao().y));
                    }
                    
                    if(getPosicao().y > outraEntidade->getPosicao().y){
                        // printf("POS X:%.f");
                         setPosicao(sf::Vector2f(getPosicao().x,getPosicao().y+distancia.y));

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

    
    void Jogador :: salvar(){}
}
}