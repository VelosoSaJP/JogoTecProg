#pragma once
#include "../Entidade.h"

namespace Entidades{
namespace Obstaculos{
    class Obstaculo : public Entidade{
        protected:
            bool danoso;
        
        public:
            Obstaculo();
            Obstaculo(sf::Vector2f pos, sf::Vector2f tam, int ID);
            ~Obstaculo();
            virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
            void executar();
            void salvar();
            virtual void empuxo()=0;
            //virtual void obstacular(Jogador*p)=0;
        };
    }
}