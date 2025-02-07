#pragma once
#include "Entidade.h"
namespace Entidades{
    class Projetil : public Entidade{
        private:
            bool ativo;
            
        public:
            Projetil();
            ~Projetil();
            void executar();
            void desenhar();


    };
}