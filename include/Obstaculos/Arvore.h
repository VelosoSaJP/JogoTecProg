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
};
}
}