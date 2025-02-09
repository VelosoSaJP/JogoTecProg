#pragma once
#include "../Entidade.h"
#include "../Personagens/Jogador.h"

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
            void desenhar();
            virtual void empuxo();
            virtual void obstacular(Personagens::Jogador* p)=0;
        };
    }
}