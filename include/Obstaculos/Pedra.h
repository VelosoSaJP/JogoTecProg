#pragma once
#include "Obstaculo.h"
namespace Entidades{
namespace Obstaculos{
    class Pedra : public Obstaculo{
        private:
            int danar;
        
        public:
            Pedra(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Pedra();
            ~Pedra();
            void executar();
            void salvar(); 
            void desenhar();
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
            void empuxo();
            void obstacular(Personagens::Jogador* p);


    };
}
}