#include "../include/Obstaculos/Pedra.h"

namespace Entidades{
namespace Obstaculos{
Pedra :: Pedra(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Obstaculo(pos,tam,ID)
{
    
}
Pedra :: Pedra(){
    
}
Pedra :: ~Pedra(){
    
}

void Pedra::executar(){
    
}
void Pedra::salvar(){
    
} 
void Pedra::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}
}
}