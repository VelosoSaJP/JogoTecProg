#pragma once

//Gerenciadores
#include "Gerenciador_Grafico.h"
#include "../Estado/Estado.h"
#include "../Estado/EstadoJogar.h"
#include "../Estado/EstadoMenu.h"
//#include "../Estado/EstadoMenuPrincipal.h"
//#include "../Estado/EstadoMenuFase.h"

//Pilha
#include <stack>


    namespace Gerenciador {

        class GerenciadorEstado {
        private:
            std::stack<Estado::Estado*> pilhaEstados;
            
            //padrão de projeto singleton
            static GerenciadorEstado* pGerenciadorEstado;
            static Gerenciadores::Gerenciador_Grafico* pGrafico;
            Estado::Estado* pEstadoAtual;
            
            GerenciadorEstado();

        public:
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executar();
            Estado::Estado* getEstado(const int qtdRemove);//hmm que isso aq?
            void addEstado(const Estado::stateID ID);
            void removerEstado(const int qtd);
            void removerEstado();
            Estado::Estado* getEstadoAtual();
        };

    }

