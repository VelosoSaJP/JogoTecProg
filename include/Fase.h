#pragma once
#include "Ente.h"
// #include "Gerenciador_Colisoes.h"
namespace Fases{
    class Fase{
        private:

        public:
            Fase();
            ~Fase();
            // void gerenciarColisoes();
            void criarPlataformas();
            virtual void criarInimigos()=0;
            virtual void criarObstaculo()=0;
            void criarCenario();
    };
}
