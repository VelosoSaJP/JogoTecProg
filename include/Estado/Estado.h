#pragma once

#include "../Ente.h"


    namespace Estado {
        
        enum stateID{
                unknown = -1,
                menuPrincipal = 0,
                jogar_floresta,
                jogar_lava

            };

        class Estado /*: public Ente*/ {
        private:
            bool remover; //state
        public:
            Estado();
            Estado(stateID ID);
            virtual ~Estado();
            virtual void executar() = 0;
            virtual void desenhar();
            void setRemover(const bool remover = true);
            const bool getRemover() const;
            //virtual void mudarEstadoObservador() = 0;
            stateID ID;
        };

    }
