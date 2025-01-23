#pragma once 

#include <SFML/Graphics.hpp>
#include "../ListaEntidade.h"
#include <math.h>
#include <list>
#include <vector>
#include <set>


class Gerenciador_Colisoes
{
private:
    Lista::ListaEntidade* listaPersonagem;
    Lista::ListaEntidade* listaObstaculo; 
    std::list<Entidades::Entidade*> LP;   
public:
    Gerenciador_Colisoes(Lista::ListaEntidade* listaPersonagem , Lista::ListaEntidade* listaObstaculo);
    
    ~Gerenciador_Colisoes();

    const sf::Vector2f gerenciaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);

    void executar();
};


