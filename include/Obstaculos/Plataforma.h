#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
    class Plataforma : public Obstaculo{

        public:
            Plataforma(sf::Vector2f pos, sf::Vector2f tam);
            Plataforma();
            ~Plataforma();

    };
}
}