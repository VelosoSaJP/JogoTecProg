#include "Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo:: Obstaculo(){

        }
        Obstaculo:: Obstaculo(sf::Vector2f pos, sf::Vector2f tam,int ID):
            Entidade(pos,tam,idOBSTACULO),
            danoso(false)
        {
            setTextura("../assets/Fases/Fase1/props/tree04.png");
        }
        Obstaculo::~Obstaculo(){

        }
        void Obstaculo :: executar(){

        }
        void Obstaculo :: salvar(){

        }

        void Obstaculo::colisao(Entidade* outraEntidade,sf::Vector2f distancia){}

    }
}