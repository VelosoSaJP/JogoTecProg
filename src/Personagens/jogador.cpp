#include "../include/Personagens/Jogador.h"
#include "../include/Gerenciadores/Gerenciador_Colisoes.h"
namespace Entidades{
namespace Personagens{
    
    Jogador::Jogador()
    {

    }

    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida):
        Personagem(sf::Vector2f(pos.x, pos.y),tam,idJOGADOR, vida),
        pGC(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
        pode_saltar(true)
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
      if(pode_saltar){
            velocidade.y= - sqrtf(gravidade * altura_pulo);
            velocidade.y*=10;   
            pode_saltar=false;                     
        }
    }
        
    void Jogador:: executar(){
        atualizaPosicao();
        hitbox();
        checarMorte();
        desenhar();

    }

    void Jogador :: desenhar(){
         
        if (pSprite){
            pGG->desenhar(pSprite); //será que dá o this?
        }
        else{
            throw std::runtime_error("o Sprite do jogador estava vazio");
        }
    }

    void Jogador:: atualizaPosicao(){
       pSprite->move(velocidade.x, velocidade.y);

    sf::Vector2f novaPosicao = pSprite->getPosition();

    if(passivelDeMovimento(novaPosicao)){

        setPosicao(novaPosicao);
    }

}

    void Jogador::andar(bool direita){
     
        if (direita){
            velocidade.x = pGG->getDeltaTime() *0.05;
            
            if (this->getPosicao().x < WIDTH) {

                if(pSprite->getScale().x < 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }
        }
        else{
            velocidade.x = -pGG->getDeltaTime() *0.05;
            if(passivelDeMovimento(this->getPosicao())){

                if(pSprite->getScale().x > 0){
                    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); 
                    pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                }
            }
        }
    }

    bool Jogador :: passivelDeMovimento(sf::Vector2f novaPosicao){
        if (novaPosicao.x > WIDTH-12){
            setPosicao(sf::Vector2f(WIDTH-15,getPosicao().y));
            return false;
        }
        else if (novaPosicao.x<10){
            setPosicao(sf::Vector2f(15,getPosicao().y));
            return false;
        }
        else{
            return true;
        }
    }
    void Jogador :: salvar(){}


void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f distancia) {
    int opt = outraEntidade->getID();
    if (opt==idPLATAFORMA || opt==idARVORE) {
            sf::Sprite* pS=outraEntidade->getSprite();
            sf::Vector2f novaPosicao = getPosicao(); 
            if (distancia.y < 0) {
                if (posicao.y > outraEntidade->getPosicao().y) {
                    novaPosicao.y = outraEntidade->getPosicao().y + pS->getGlobalBounds().height/2;
                } else {
                    novaPosicao.y = outraEntidade->getPosicao().y - pSprite->getGlobalBounds().height/2;
                }
            }

            else if (distancia.x < 0) {
                if (posicao.x > outraEntidade->getPosicao().x) {
                    novaPosicao.x = outraEntidade->getPosicao().x + pS->getGlobalBounds().width/2;
                } else {
                    novaPosicao.x = outraEntidade->getPosicao().x - pS->getGlobalBounds().width/2;
                }
            }
            novaPosicao.y-=25;
            setPosicao(novaPosicao);
    }

    else if(opt==idESQUELETO){
                if (distancia.x<distancia.y){
                    if(outraEntidade->getPosicao().y>=posicao.y+40){
                        printf("esqueleto toma dano\n");
                    }
                    else{
                        printf("jogador toma dano\n");
                    }
            }
        }

    else if(opt==idORC){
                if (distancia.x<distancia.y){
                    if(outraEntidade->getPosicao().y>=posicao.y+40){
                        printf("orc toma dano\n");
                    }
                    else{
                        printf("jogador toma dano\n");
                    }
            }
    }


    else if (opt==idMAGO){
                 if (distancia.x<distancia.y){
                    if(outraEntidade->getPosicao().y>=posicao.y+40){
                        printf("mago toma dano\n");
                    }
                    else{
                        printf("jogador toma dano\n");
                    }
            }

     }      
}

void Jogador::setPodeSaltar(bool permissao){
    pode_saltar=permissao;
}
}
}