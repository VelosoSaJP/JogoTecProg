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
         sf::Vector2f ds = gerenciaColisao(ent1, ent2);
             if(ds.y < 225.0f){ //225 é um valor que vale para ambas as fases. O boneco não começa em 0, pois há um altura do chão.
               return true;//tá no chão
             }
             else{
                return false;
             }
    }
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
        sf::Vector2f pos1 = ent1->getPosicao();
        sf::Vector2f pos2 = ent2->getPosicao();
        sf::Vector2f tam1 = ent1->getTam();
        sf::Vector2f tam2 = ent2->getTam();
        sf::Vector2f distanciaEntreCentros(fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
            fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f)));

        sf::Vector2f somaMetadeRetangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);
        return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);

    }
}

void Gerenciador_Colisoes::executar(){
       //PERSONAGEM COM PERSONAGEM
    for(int i = 0; i < listaPersonagem->getTamanho() - 1; i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
        for(int j = i + 1; j < listaPersonagem->getTamanho(); j++){
        
            Entidades::Entidade* ent2 = listaPersonagem->getLista().operator[](j); //O SEG FAULT TÁ AQUI.
            sf::Vector2f ds = gerenciaColisao(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent1->colisao(ent2, ds);
            } 
        }
    }
    
    //PERSONAGEM COM OBSTÁCULO
    for(int i = 0; i < listaPersonagem->getTamanho(); i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
        for(int j = 0; j < listaObstaculo->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
            sf::Vector2f ds = gerenciaColisao(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent2->colisao(ent1, ds);
            }
        }
    }
 }
}




