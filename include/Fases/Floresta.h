#pragma once
#include "Fase.h"

namespace Fases{
    class Floresta : public Fase{
        private:
        bool criaArvore_alteatoria;
        int aux_arv_floresta;

        public:
            Floresta();
            ~Floresta();
            void criarFase();
            void criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            void criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho);
            string getCaminhoMapa();
           
            
    };
}