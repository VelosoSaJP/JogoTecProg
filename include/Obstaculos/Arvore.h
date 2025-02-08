#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
class Arvore : public Obstaculo{
    private:
    
    public:
    Arvore(sf::Vector2f pos, sf::Vector2f tam, int ID);
    Arvore();
    ~Arvore();
    void executar();
    void salvar(); 
    void desenhar();
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);

};
}
}