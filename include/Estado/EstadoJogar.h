#pragma once

#include "Estado.h"

//Gerenciador
#include "../Gerenciadores/Gerenciador_Grafico.h"   
#include "../Gerenciadores/Gerenciador_Estado.h"

//Fases
/*
#include "../Fases/Floresta.h"
#include "../Fases/Lava.h"
#include "../Fases/Fase.h"
*/
//class Fase;
namespace Fases{
    class Fase;    //krl o peixe eh muitooooo bommmmmm
    class Floresta;
    class Lava;
}
#include <map>

    namespace Estado {

        class EstadoJogar : public Estado {
        private:
            //std::map<IDs::IDs, Fase::Fase*> mapFase;
            stateID ID_FaseAtual;
            Fases::Floresta* pFaseFloresta;
            Fases::Lava* pFaseLava;
            Gerenciadores::Gerenciador_Grafico* pGGrafico;
            //Gerenciador::GerenciadorEstado* pGEstado;
            Fases::Fase* pFase;
            
            
        public:
            EstadoJogar();
            EstadoJogar(stateID ID);
            ~EstadoJogar();
            //void criarFase(const std::string arquivoEntidades, std::vector<std::string> vectorInfoFase);
            //acho que não vou precisar dessa^^
            //void criarFase();
            //nem dessa^^
            //std::map<IDs::IDs, Fase::Fase*> getMapFase();
            const stateID getIDFaseAtual() const;
            Fases::Fase* getFase();
            void mudarFase(const stateID ID_Fase);
            //void mudarEstadoObservador();
            void executar();
        };

    }

