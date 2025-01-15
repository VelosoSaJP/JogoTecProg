#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo:: Obstaculo(){

        }
        Obstaculo:: Obstaculo(sf::Vector2f pos, sf::Vector2f tam):
            Entidade(pos,tam),
            danoso(false)
        {
            setTextura("../assets/Fases/Fase1/props/arvore4.png");
        }
        Obstaculo::~Obstaculo(){

        }
        void Obstaculo :: executar(){

        }
        void Obstaculo :: salvar(){

        }
    }
}