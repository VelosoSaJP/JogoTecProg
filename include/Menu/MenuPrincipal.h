#pragma once

#include"Gerenciadores/Gerenciador_Grafico.h"
#include "Menu.h"
#include "../Estado/Estado.h"
//#define CAMINHO_TEXTURA_MENU_PRINCIPAL "Jungle++/img/Menu/menuPrincipal.png"


    namespace Menu {

        class MenuPrincipal: public Menu {
        protected:
            //Parallax::Fundo fundo;
            Gerenciadores::Gerenciador_Grafico* pGrafico;
            sf::Text texto;

        private:
            void criarFundo();
            
        public:
            MenuPrincipal();
            MenuPrincipal(const Estado::stateID ID, std::string nome, const unsigned int tamFonte = 180);
            virtual ~MenuPrincipal();
            virtual void criarBotoes();
            virtual void executar();
        };

    } 

