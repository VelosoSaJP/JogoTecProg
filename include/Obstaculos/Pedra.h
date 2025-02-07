#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
    class Pedra : public Obstaculo{

        public:
            Pedra(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Pedra();
            ~Pedra();
            void executar();
            void salvar(); 
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);


    };
}
}