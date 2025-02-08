#pragma once
#include "Inimigo.h"

namespace Entidades{
namespace Personagens{
class Orc : public Inimigo{
    private:
        int vida;

    public:
    Orc(sf::Vector2f pos, sf::Vector2f tam, int ID);
    Orc();
    ~Orc();
    void executar();
    void desenhar();
    void danificar(Jogador* p);
    void salvar();
    void empuxo();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
};

}
}