#pragma once
#include "Obstaculo.h"
#include "/home/murilo/code/JogoTecProg/include/Personagens/Jogador.h"

namespace Entidades{
namespace Obstaculos{
    class Fogo : public Obstaculo{
        int danar;
        public:
            Fogo(sf::Vector2f pos, sf::Vector2f tam, int ID);
            Fogo();
            ~Fogo();
            void desenhar();
            void executar();
            void salvar(); 
            void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
            void empuxo();
            void obstacular(Personagens::Jogador* jog);



    };
}
}