#pragma once 

#include "../Ente.h"
//#include "Botao/BotaoTexto.hpp"
//#include "Botao/Texto.hpp"
#include "Botao/Botao.h"

#include <list>
#include "../Estado/Estado.h"

#define TAMANHO_BOTAO_X 350.0f
#define TAMANHO_BOTAO_Y 50.0f


    namespace Menu {

        class Menu: public Ente {
        protected:
            //Observador::ObservadorMenu* observadorMenu;
            //std::list<Botao::BotaoTexto*> listaBotaoTexto;
            //std::list<Botao::BotaoTexto*>::iterator it;     // acho que n voou ter esses textos aq
            std::vector<sf::Text> vetorBotao;
            const sf::Vector2f tamBotao;
            const sf::Vector2f tamJanela;
            sf::Vector2f posFundo;
            sf::Text titulo;
//            sf::Text texto;
            bool mouseSelecionado;
            Gerenciadores::Gerenciador_Grafico* pGrafico;

            //void atualizarPosicaoFundo();
            virtual void criarFundo(){};
            virtual void criarBotoes() = 0;
            void inicializarIterator();
        
        public:
            Menu(const Estado::stateID ID, const sf::Vector2f tamBotao, const std::string nome, const unsigned int tamFonte);
            ~Menu();
            void addBotao(const std::string info, const sf::Vector2f pos, const Estado::stateID ID, const sf::Color corSelecionado);
            //void mudarEstadoObservador();
            void selecionaCima();
            void selecionaBaixo();
            virtual void selecionaEsquerda(){}
            virtual void selecionaDireita(){}
            const Estado::stateID getIDBotaoSelecionado() const;
            void eventoMouse(const sf::Vector2f posMouse);
            const bool getMouseSelecionado() const;
            virtual void executar() = 0;
            void desenhar();
        };

    }
    
