#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
class Arvore : public Obstaculo{
    private:
        float lentidao;
    public:
    Arvore(sf::Vector2f pos, sf::Vector2f tam, int ID);
    Arvore();
    ~Arvore();
    void executar();
    void salvar(); 
    void desenhar();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    void empuxo();
    void obstacular(Personagens::Jogador* p);

};
}
}