#include "../include/Personagem.h"
namespace Entidades{
namespace Personagens{
    Personagem::Personagem(){

    }
    Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam):
        Entidade(pos,tam),
        velocidade(0),
        num_vidas(0)
    {
    }
    Personagem::~Personagem(){

    }      

    int const Personagem::getVidas(){

    }

    // void Personagem::salvar (){}
   // void Personagem::executar(){}
    // Personagem:: salvarDataBuffer(){}
    // Personagem::  void mover()=0{}
}}