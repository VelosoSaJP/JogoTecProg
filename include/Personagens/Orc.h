#pragma once
#include "Inimigo.h"

namespace Entidades{
namespace Personagens{
class Orc : public Inimigo{
    private:
        int vida;

    public:
    Orc(sf::Vector2f pos, sf::Vector2f tam);
    Orc();
    ~Orc();
    void executar();
    void danificar(Jogador* p);
    void salvar();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
};

}
}