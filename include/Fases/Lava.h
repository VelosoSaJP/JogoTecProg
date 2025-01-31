#pragma once
#include "Fase.h"

namespace Fases{
    class Lava : public Fase{
        private:
            bool lava;


         public:
            Lava();
            ~Lava();
            void criarFase();
            void criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            const char* getCaminhoMapa();
    };
}