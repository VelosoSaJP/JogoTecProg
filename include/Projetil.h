#pragma once
#include "Entidade.h"
namespace Entidades{
    class Projetil : public Entidade{
        private:
            int dano;
            
        public:
            Projetil(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Projetil();
            ~Projetil();
            void executar();
            void desenhar();
             void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
             void salvar(); 
             void arremesado();


    };
}