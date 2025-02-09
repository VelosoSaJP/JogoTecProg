#pragma once

#include "Estado.h"
#include "../Fases/Fase.h"
#include "../Menu/Menu.h"
//#include "../Gerenciadores/Gerenciador_Grafico.h"
#include <vector>

    namespace Gerenciador {
        class GerenciadorEstado;
    }

    namespace Estado {

        class EstadoMenu : public Estado, public Ente {
            private:
                Menu::Menu* menu;

                static Gerenciador::GerenciadorEstado* pGEstado;
                //Gerenciadores::Gerenciador_Grafico* pGG;
                Gerenciadores::Gerenciador_Eventos* pGE;

                void criarMenu();

                std::vector<sf::Text> opcoes;
                sf::Font fonte;
                
                sf::Texture texturaFundo;
                sf::Sprite fundo;
            public:
                EstadoMenu(const stateID ID);
                ~EstadoMenu();
                //void mudarEstadoObservador();
                Fases::Fase* getFase();
                Menu::Menu* getMenu();
                void executar();
        };

    }
