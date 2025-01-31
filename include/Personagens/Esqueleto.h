#pragma once
#include "Inimigo.h"


namespace Entidades{
namespace Personagens{
class Esqueleto : public Inimigo{
    private:
        int vida;

    public:
    Esqueleto(sf::Vector2f pos, sf::Vector2f tam);
    Esqueleto();
    ~Esqueleto();
    void executar();
    void danificar(Jogador* p);
    void salvar();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
};

}
}