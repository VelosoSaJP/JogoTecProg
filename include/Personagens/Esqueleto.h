#pragma once
#include "Inimigo.h"


namespace Entidades{
namespace Personagens{
class Esqueleto : public Inimigo{
    private:
        int mordida;
    public:
    Esqueleto(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida, int dano);
    Esqueleto();
    ~Esqueleto();
    void desenhar();
    void executar();
    void tomarDano(int dano_sofrido);
    void danificar(Jogador* p);
    void salvar();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    void empuxo();
};

}
}