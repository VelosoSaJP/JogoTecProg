#include "/home/murilo/code/JogoTecProg/include/Personagens/Esqueleto.h"
namespace Entidades{
namespace Personagens{

Esqueleto :: Esqueleto(sf::Vector2f pos, sf::Vector2f tam):
    Inimigo(pos,tam),
    vida(100){
}

Esqueleto :: Esqueleto(){

}

Esqueleto :: ~Esqueleto(){

}

void Esqueleto :: executar(){

}
void Esqueleto :: danificar(Jogador* p){
     
}

void Esqueleto::salvar(){

}
void Esqueleto::colisao(Entidade* outraEntidade,sf::Vector2f distancia){
    
}



}
}