#pragma once
#include "../Entidade.h"

namespace Entidades{
namespace Obstaculos{
    class Obstaculo : public Entidade{
        protected:
            bool danoso;
        
        public:
            Obstaculo();
            Obstaculo(sf::Vector2f pos, sf::Vector2f tam);
            ~Obstaculo();
            void executar ();
            void salvar();
            //virtual void obstacular(Jogador*p)=0;
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
        };
    }
}