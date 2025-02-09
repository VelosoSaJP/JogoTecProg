#include "../include/Personagens/Jogador.h"
#include "../include/Gerenciadores/Gerenciador_Colisoes.h"
namespace Entidades{
namespace Personagens{
    
    Jogador::Jogador()
    {

    }

    Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida):
        Personagem(sf::Vector2f(pos.x, pos.y),tam,idJOGADOR, vida),
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
            if(pGC->NoChao(this)){
                //  printf("Tá vindo aqui\n");
                    velocidade.y= - sqrtf(gravidade * altura_pulo);
                    velocidade.y*=10;     
                             
         }
            else{
                //    printf("Não estava no chão\n");
            }
        }
    }
        
    void Jogador:: executar(){
        atualizaPosicao();
        hitbox();
        desenhar();

    }


    void Jogador :: desenhar(){
         
        if (pSprite){
            // sf::RectangleShape desenhaColisao;
            // desenhaColisao.setFillColor(sf::Color::Transparent);
            // desenhaColisao.setOutlineColor(sf::Color::Yellow);
            // sf::Vector2f posicaoColisao;
            // sf::Vector2f tamanhoColisao;
        // 
            // posicaoColisao={pSprite->getGlobalBounds().left,pSprite->getGlobalBounds().top};
            // tamanhoColisao={pSprite->getGlobalBounds().width,pSprite->getGlobalBounds().height};
            // desenhaColisao.setSize(tamanhoColisao*0.8f);
            // desenhaColisao.setPosition(posicaoColisao);
// 
            // desenhaColisao.setOutlineThickness(1.f);
            
            pGG->desenhar(pSprite); //será que dá o this?
            // pGG->desenhar(desenhaColisao);
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
    switch (opt) {
        case (idOBSTACULO): {
            sf::Sprite* pS=outraEntidade->getSprite();
            
            sf::Vector2f novaPosicao = getPosicao(); // Posição atual do jogador

            // Se estiver colidindo no eixo X, ajusta a posição X
            if (distancia.y < 0) {
                setPodeSaltar(false);
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

bool Jogador::getPodeSaltar(){
    return pode_saltar;
}

 void Jogador::setPodeSaltar(bool permissao){
     pode_saltar=permissao;
}
}
}