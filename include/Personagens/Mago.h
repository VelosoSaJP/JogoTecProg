#pragma once
#include "Inimigo.h"
#include "../Projetil.h"
#include "../Listas/ListaEntidade.h"

namespace Entidades{
namespace Personagens{
class Mago : public Inimigo{
    private:
        Entidades::Projetil* pProjetil;
        Lista::ListaEntidade* pLE;
        int poder; //o mago ataca fisicamente também.

    public:
    Mago(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida, int dano);
    Mago();
    ~Mago();
    void executar();
    void salvar();
    void desenhar();
    void danificar(Jogador* p);
    void empuxo();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    void atacar(sf::Vector2f pos, sf::Vector2f tam, int ID);
    void setLista(Lista::ListaEntidade* pLista);

    
};

}
}