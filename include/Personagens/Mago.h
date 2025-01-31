#pragma once
#include "Inimigo.h"


namespace Entidades{
namespace Personagens{
class Mago : public Inimigo{
    private:
        int vida;

    public:
    Mago(sf::Vector2f pos, sf::Vector2f tam);
    Mago();
    ~Mago();
    void executar();
    void salvar();
    void danificar(Jogador* p);
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    
};

}
}