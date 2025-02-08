#include "../include/Obstaculos/Obstaculo.h"

namespace Entidades{
    namespace Obstaculos{
        Obstaculo:: Obstaculo(){

        }
        Obstaculo:: Obstaculo(sf::Vector2f pos, sf::Vector2f tam,int ID):
            Entidade(pos,tam,idOBSTACULO),
            danoso(false)
        {
        }
        Obstaculo::~Obstaculo(){

        }
        void Obstaculo :: executar(){
            desenhar();
        }

        void Obstaculo :: desenhar(){
       }
        void Obstaculo :: salvar(){

        }
         void Obstaculo::empuxo(){}



    }
}