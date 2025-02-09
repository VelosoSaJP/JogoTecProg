#include "../include/Personagens/Mago.h"
namespace Entidades{
namespace Personagens{

Mago :: Mago(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida,int dano):
    Inimigo(pos,tam,idMAGO,vida, dano),
    pProjetil(nullptr),
     pLE(nullptr),
     poder(dano) //o mago ataca fisicamente também.

{   
   
}

Mago :: Mago(){
//pProjetil será desalocado da memória em lista.
    if(pLE){
        pLE=nullptr;
    }
}

Mago :: ~Mago(){

}

void Mago :: setLista(Lista::ListaEntidade* pLista){
   if(pLista){
        pLE=pLista;
   }
  
}
void Mago :: executar(){
    desenhar();
    empuxo();
    checarMorte();
}

void Mago:: desenhar(){
    if (pSprite){
        pGG->desenhar(pSprite);
    }
    else{
        throw std::runtime_error("o Sprite do mago estava vazio");
    }
}


void Mago :: danificar(Jogador* p){
      if(p){
        p->tomarDano(getVida()-poder);
      }
}
void Mago :: salvar(){
    
}
void Mago::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Mago::empuxo(){
    gravidade=0;
    velocidade.y=0;
}
void Mago::atacar(sf::Vector2f pos, sf::Vector2f tam, int ID){

    // pProjetil = new Entidades::Projetil (pos,tam,idPROJETIL);//adicionar na lista.
    // pProjetil->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Mago/projetil.png");
    // pLE->incluir(static_cast<Entidades::Entidade *> (pProjetil));
// 
// 
    // printf("VEIO NO MAGO\n");

}

}
}