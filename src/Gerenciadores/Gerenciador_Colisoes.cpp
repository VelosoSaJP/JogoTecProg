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

const sf::Vector2f Gerenciador_Colisoes::gerenciaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2){
    if(ent1 && ent2){
        sf::Vector2f pos1 = ent1->getPosicaoMovel()- ent1->getOrigem();      //ENTE 1 VAI SER SEMPRE ENTIDADE MÓVEL.  
        sf::Vector2f pos2 = ent2->getPosicaoEstatica() - ent2->getOrigem();

       /*// if(ent2->getID()==idJOGADOR || ent2->getID()==idESQUELETO|| ent2->getID()==idMAGO|| ent2->getID()==idORC){
            sf::Vector2f pos2 = ent2->getPosicaoMovel() - ent2->getOrigem();
        }
        else{
            sf::Vector2f pos2 = ent2->getPosicaoEstatica() - ent2->getOrigem();
        }*/ 
        // printf("ENT1 em x: %.0f, em y: %.0f\n",pos1.x,pos1.y);
        // printf("ENT2 em x: %.0f, em y: %.0f\n",pos2.x,pos2.y);

        sf::Vector2f tam1 = ent1->getTam();
        sf::Vector2f tam2 = ent2->getTam();
        sf::Vector2f distanciaEntreCentros(
            fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
            fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f))
        );

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
        if (ent1 && ent1->getID()==1){
            for(int j = 0; j < listaObstaculo->getTamanho(); j++){
                Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
                
                if (ent2){
                    sf::Vector2f ds = gerenciaColisao(ent1, ent2);


                    if(ds.x < 0.0f && ds.y < 0.0f){
                    // printf("ENT2 em x: %.0f, em y: %.0f\n",ent2->getPosicaoEstatica().x,ent2->getPosicaoEstatica().y);
                    // printf("ENT1 em x: %.0f, em y: %.0f\n",ent1->getPosicaoMovel().x,ent1->getPosicaoMovel().y);
                    // printf("ds em x: %.0f, em y: %.0f\n",ds.x,ds.y);
                        // exit(1);
                        // printf("Entrou em ds\n");
                        ent1->colisao(ent2, ds);
                    }
                }
            }
        }
    }
 }
}




