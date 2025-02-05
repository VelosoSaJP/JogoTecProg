#pragma once 

#include <SFML/Graphics.hpp>
#include "../Listas/ListaEntidade.h"
#include "../Listas/Lista.h"
#include <math.h>
#include <list>
#include <vector>
#include <set>
#include <Ente.h>

namespace Gerenciadores{
class Gerenciador_Colisoes
{
private:
    static Gerenciador_Colisoes* instancia;
    Lista::ListaEntidade* listaPersonagem;
    Lista::ListaEntidade* listaObstaculo; 
    Lista::Lista<Entidades::Entidade> ListaEntidade;
    std::list<Entidades::Entidade*> LP;   

private:
    Gerenciador_Colisoes();

public:
    ~Gerenciador_Colisoes();
     void setListas(Lista::ListaEntidade* lPers, Lista::ListaEntidade* lObs);
    static Gerenciador_Colisoes* getInstancia() ;
    bool NoChao(Entidades::Entidade* ent1);

    const sf::Vector2f gerenciaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);

    void executar();
};


}