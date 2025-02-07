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
 
 bool Gerenciador_Colisoes :: NoChao(Entidades::Entidade* ent1){
   if(ent1){

    for(int j = 0; j < listaObstaculo->getTamanho(); j++){
        Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
            
        if (ent2){
            sf::Vector2f ds = gerenciaColisao(ent1, ent2);
            if(ds.y < 0.0f){
                printf("TÁ NO CHÃO\n");
                    return false;//está no chão.
            }
            else{
                printf("Não tá no chão\n");
                return true;
            }
        }
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
  
 }
 }

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
/*
        sf::Vector2f posicao1 = ent1->getPosicao();
        sf::Vector2f posicao2 = ent2->getPosicao();
        sf::Vector2f tamanho1 = ent1->getTamanho();
        sf::Vector2f tamanho2 = ent2->getTamanho();

        sf::Vector2f dcolisao(0,0);
        dcolisao.x = tamanho1.x/2.0+tamanho2.x/2.0;
        dcolisao.y = tamanho1.y/2.0+tamanho2.y/2.0;

        sf::Vector2f distancia(0,0); //EU SETEI A MINHA ORIGEM NO CENTRO DO SPRITE.
        distancia.x= fabs(ent1->getPosicao().x-ent2->getPosicao().y);
        distancia.y= fabs(ent1->getPosicao().y-ent2->getPosicao().y);

        // if(distancia.x){
            // TAMANHO MUITO PEQUENO
        // }
        // printf("distancia: x= %f e y= %f\n",distancia.x,distancia.y);
        // printf("colisao: x= %f e y= %f\n",dcolisao.x,dcolisao.y);

        if(distancia.y<dcolisao.y && distancia.x<dcolisao.x){
            printf("ENT1: x= %.1f e y= %.1f\n",ent1->getPosicao().x,ent1->getPosicao().y);
            printf("ENT2: x= %.1f e y= %.1f\n",ent2->getPosicao().x,ent2->getPosicao().y);
            exit(1);

        }
     
     return distancia;*/

    
        sf::Vector2f pos1 = ent1->getPosicao();
        sf::Vector2f pos2 = ent2->getPosicao();
        sf::Vector2f tam1 = ent1->getTamanho();
        sf::Vector2f tam2 = ent2->getTamanho();
        sf::Vector2f distanciaEntreCentros(fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
            fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f)));

        sf::Vector2f somaMetadeRetangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
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
        sf::Sprite* reposicionando1=nullptr;
        sf::Sprite* reposicionando2=nullptr;
        
        if (ent1 && ent1->getID()==1){

            sf::Sprite* reposicionando1 = ent1->getSprite();
            reposicionando1->setOrigin(reposicionando1->getGlobalBounds().width / 2, reposicionando1->getGlobalBounds().height / 2);


        if (ent1 && ent1->getID()==1){
            for(int j = 0; j < listaObstaculo->getTamanho(); j++){
                Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
               sf::Sprite* reposicionando2 = ent2->getSprite();
            reposicionando2->setOrigin(reposicionando2->getGlobalBounds().width / 2, reposicionando2->getGlobalBounds().height / 2);

                if (ent2){
                    sf::Vector2f ds = gerenciaColisao(ent1, ent2);

                    if (ds.x < 0.0f && ds.y < 0.0f) {
                        // printf("Tá colidindo\n");
                        // ent1->setPosicao(sf::Vector2f(300,150));
                        
                         ent1->colisao(ent2, ds);
                    }
                }
            }
        }
    }
 }
}
}




