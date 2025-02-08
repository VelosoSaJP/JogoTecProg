#include "../include/Obstaculos/Pedra.h"

namespace Entidades{
namespace Obstaculos{
Pedra :: Pedra(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Obstaculo(pos,tam,ID)
{
    executar();
}
Pedra :: Pedra(){
    
}
Pedra :: ~Pedra(){
    
}

void Pedra::executar(){
    desenhar();
}
void Pedra::salvar(){
    
} 

void Pedra::desenhar(){
    
}

void Pedra::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

void Pedra::empuxo(){
    gravidade=0;
}
}
}