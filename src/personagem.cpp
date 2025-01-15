#include "../include/Personagem.h"
namespace Entidades{
namespace Personagens{
    Personagem::Personagem(){

    }
    Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam):
        Entidade(pos,tam),
        num_vidas(0)
    {
    }
    Personagem::~Personagem(){

    }      

    int const Personagem::getVidas(){
        return num_vidas;
    }

    // void Personagem::salvar (){}
   // void Personagem::executar(){}
    // Personagem:: salvarDataBuffer(){}
    /*void Entidades::Entidade::mover(){
        // aqui entra pos+=velocidade, tipo isso
    }*/


    
}}