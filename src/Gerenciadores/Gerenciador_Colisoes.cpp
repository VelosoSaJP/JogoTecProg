#include "../include/Gerenciadores/Gerenciador_Colisoes.h"

namespace Gerenciadores{
Gerenciador_Colisoes* Gerenciador_Colisoes :: instancia(nullptr);


Gerenciador_Colisoes* Gerenciador_Colisoes :: getInstancia(){
    if (instancia == NULL){
        instancia = new Gerenciador_Colisoes();
    }
        return instancia;
}
Gerenciador_Colisoes::Gerenciador_Colisoes():
 listaPersonagem(nullptr),
 listaObstaculo(nullptr){
}
 
 bool Gerenciador_Colisoes::NoChao(Entidades::Entidade* ent1) {
    // if (ent1) {   
// 
        // for (int j = 0; j < listaObstaculo->getTamanho(); j++) {
            // Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
// 
            // if (ent2) {
                // sf::Vector2f ds = gerenciaColisao(ent1, ent2);
                // if (ds.x < 0.0f && ds.y < 0.0f) {  
                    // ent1->setPodeSaltar(false);  // Só libera salto se houver colisão com o chão
                    // return true;
                // }
            // }   
        // }
    // }
    // ent1->setPodeSaltar(true);
    // return false;  // Se nenhuma colisão foi detectada, retorna falso
}



   /* for(int j = 0; j < listaObstaculo->getTamanho(); j++){
         Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
         sf::Vector2f ds = gerenciaColisao(ent1, ent2);
             if(ds.y < 0){ //225 é um valor que vale para ambas as fases. O boneco não começa em 0, pois há um altura do chão.
               return true;//tá no chão
             }
             else{
                return false;
             }*/
  

void Gerenciador_Colisoes::setListas(Lista::ListaEntidade* lPers, Lista::ListaEntidade* lObs){
   if (lPers){
        listaPersonagem = lPers;
    }
    if(lObs){
        listaObstaculo = lObs;
    }
    
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
     listaPersonagem=nullptr;
     listaObstaculo=nullptr;
    // delete listaObstaculo; //vai direto para o método limpar das listas.
    // delete listaPersonagem;
}

const sf::Vector2f Gerenciador_Colisoes::gerenciaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2) {
      if(ent1 && ent2){

     sf::Sprite* pSprite1 = ent1->getSprite();
     sf::Sprite* pSprite2 = ent2->getSprite();

    sf::Vector2f tam_hitbox1={pSprite1->getGlobalBounds().width, pSprite1->getGlobalBounds().height / 2};
     sf::Vector2f pos_hitbox1 ={pSprite1->getGlobalBounds().left, pSprite1->getGlobalBounds().top + pSprite1->getGlobalBounds().height / 2};


     sf::Vector2f pos_hitbox2 ={pSprite2->getGlobalBounds().left, pSprite2->getGlobalBounds().top};
     sf::Vector2f tam_hitbox2 ={pSprite2->getGlobalBounds().width,pSprite2->getGlobalBounds().height};


     tam_hitbox1.x*=0.5;

     pos_hitbox1.x += (pSprite1->getGlobalBounds().width * (1 - 0.6)) / 2;


        sf::Vector2f distanciaEntreCentros(fabs((pos_hitbox1.x + tam_hitbox1.x/2.0f) - (pos_hitbox2.x + tam_hitbox2.x/2.0f)),
            fabs((pos_hitbox1.y + tam_hitbox1.y/2.0f) - (pos_hitbox2.y + tam_hitbox2.y/2.0f)));
 
       
 
        sf::Vector2f somaMetadeRetangulo(tam_hitbox1.x/2.0f + tam_hitbox2.x/2.0f, tam_hitbox1.y/2.0f + tam_hitbox2.y/2.0f);

        return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

    
}
}

void Gerenciador_Colisoes::executar(){
   /*      //PERSONAGEM COM PERSONAGEM
    for(int i = 0; i < listaPersonagem->getTamanho() - 1; i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
        //  printf("%d\n",ent1->getID());
            
        if (ent1){
            for(int j = i + 1; j < listaPersonagem->getTamanho(); j++){
            
                Entidades::Entidade* ent2 = listaPersonagem->getLista().operator[](j);
         
                //  printf("ent 1: %d e ent2: %d\n",ent1->getID(),ent2->getID());
                if(ent2){
                    sf::Vector2f ds = gerenciaColisao(ent1, ent2);
                    // if(ent1->getID()==1){
                    //      printf("em x: %f e em y: %f\n",ds.x,ds.y);
                    //      cout<<"ds.x: "<<ds.x->getPosicao().x<<"ds.y: "<<ds.y->getPosicao().y<<endl;
                    // }
                        if(ds.x < 0.0f && ds.y < 0.0f){
                            // printf("Entrou no primeiro for\n");
                            ent1->colisao(ent2, ds);
                        } 
                }
            }
        }
    }
  */
    //PERSONAGEM COM OBSTÁCULO
    for(int i = 0; i < listaPersonagem->getTamanho(); i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
    
        if (ent1 && ent1->getID()==1){//SE EU TIRAR O ID, O BONECO PARA DE FICAR PRESO EM LAVA

            for(int j = 0; j < listaObstaculo->getTamanho(); j++){
                Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
                
               if (ent2){

                    sf::Vector2f ds = gerenciaColisao(ent1, ent2);
    
                             

                        //   printf("PEDRA posicao x= %.1f e y=%.1f\n",ent1->getPosicao().x,ent1->getPosicao().y);
                    if (ds.x < 0.0f && ds.y < 0.0f) {
                       
                        if(ent2->getID()==idFOGO){
                            printf("Entrando\n");
                            Entidades::Obstaculos::Fogo* fogo = dynamic_cast< Entidades::Obstaculos::Fogo*>(ent2);
                            Entidades::Personagens::Jogador* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(ent1);
                            fogo->obstacular(jogador);
                        }
                        if(ent2->getID()==idPEDRA){
                            Entidades::Obstaculos::Pedra* pedra = dynamic_cast< Entidades::Obstaculos::Pedra*>(ent2);
                            Entidades::Personagens::Jogador* jogador = dynamic_cast<Entidades::Personagens::Jogador*>(ent1);
                            pedra->obstacular(jogador);
                        }

                        
                         ent1->colisao(ent2, ds);
                    }
                }
            }
        }
    }
 }
}





