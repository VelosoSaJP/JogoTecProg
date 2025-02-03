#pragma once
#include "Fase.h"

namespace Fases{
    class Lava : public Fase{
        private:
            int aux_arvore;
            bool cria_textura_arv;


         public:
            Lava();
            ~Lava();
            void criarFase();
            void criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            string getCaminhoMapa();
    };
}