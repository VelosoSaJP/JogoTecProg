#pragma once
#include "Obstaculo.h"

namespace Entidades{
namespace Obstaculos{
    class Plataforma : public Obstaculo{
        private:
            int venenosa;
        public:
            Plataforma(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Plataforma();
            ~Plataforma();
            void executar();
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
            void salvar(); 
            void desenhar();
            void empuxo();
            void obstacular(Personagens::Jogador* p);
    };
}
}