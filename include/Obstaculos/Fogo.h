#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
    class Fogo : public Obstaculo{

        public:
            Fogo(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Fogo();
            ~Fogo();
            void executar();
            void salvar(); 
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
            void empuxo();


    };
}
}