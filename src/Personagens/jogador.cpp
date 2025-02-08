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
            printf("Tá vindo aqui\n");
            if(pGC->NoChao(this)){
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
    if(passivelDeMovimento(novaPosicao)){

        setPosicao(novaPosicao);
    }


    pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getLocalBounds().height / 2);


    }

    void Jogador::andar(bool direita){
        velocidade.y=0;
     
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
       void Entidades::Personagens::Jogador::colisao(Entidade* outraEntidade, sf::Vector2f distancia) {
    int opt = outraEntidade->getID();
    switch (opt) {
        case (idOBSTACULO): {
            sf::Vector2f novaPosicao = getPosicao(); // Posição atual do jogador

            // Se estiver colidindo no eixo X, ajusta a posição X

            if (distancia.y < 0) {
                if (posicao.y > outraEntidade->getPosicao().y) {
                    novaPosicao.y = outraEntidade->getPosicao().y + outraEntidade->getTamanho().y;
                } else {
                    novaPosicao.y = outraEntidade->getPosicao().y - getTamanho().y;
                }
            }

            else if (distancia.x < 0) {
                    printf("Veio aqui\n");
                if (posicao.x > outraEntidade->getPosicao().x) {
                    novaPosicao.x = outraEntidade->getPosicao().x + outraEntidade->getTamanho().x;
                } else {
                    novaPosicao.x = outraEntidade->getPosicao().x - getTamanho().x;
                }
                    printf("DIST em X: %1.f\n",distancia.x);
                    printf("DIST em Y: %1.f\n",distancia.y);
                    exit(1);
            }

            setPosicao(novaPosicao); // Atualiza a posição do jogador

            break;
        }

            
            case(idESQUELETO): 
                {
                        //SE FOR EM X-> ESQUELETO DA DANO NO JOG, SE FOR EM Y-> JOG DA DANO EM ESQUELETO.
                }
            default:
                break;
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
}
}