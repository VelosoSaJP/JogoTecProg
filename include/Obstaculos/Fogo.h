#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
    class Fogo : public Obstaculo{

        public:
            Fogo(sf::Vector2f pos, sf::Vector2f tam);
            Fogo();
            ~Fogo();

    };
}
}