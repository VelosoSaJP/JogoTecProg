#include "../../include/Menu/MenuPrincipal.h"


    namespace Menu {

        MenuPrincipal::MenuPrincipal():
            Menu(Estado::stateID::menuPrincipal, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), "IDADE MEDIA ++", 180)
            //,fundo(Estado::stateID::fundo_florestaNegra)
        {
            titulo.setPosition(sf::Vector2f(tamJanela.x / 2.0f /*- titulo.getTam().x / 2.0f*/, 25.0f));
            titulo.setFillColor(sf::Color{0,200,0});
            criarFundo();
        }

        MenuPrincipal::MenuPrincipal(const Estado::stateID ID, std::string nome, const unsigned int tamFonte):
            Menu(ID, sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), nome, tamFonte) 
            //fundo(Estado::stateID::fundo_florestaNegra)
        {
            titulo.setPosition(sf::Vector2f(tamJanela.x / 2.0f /*- titulo.getTam().x / 2.0f*/, 25.0f));
            titulo.setFillColor(sf::Color{0,200,0});

            criarFundo();
        }

        MenuPrincipal::~MenuPrincipal(){
            
        }

        void MenuPrincipal::criarFundo(){
         /*
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada1.png", 0.0f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada2.png", 0.05f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada3.png", 0.1f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada4.png", 0.15f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada5.png", 0.2f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada6.png", 0.4f);
            fundo.addCamada("Jungle++/img/Fase/FlorestaNegra/camada7.png", 0.6f);
         */  
        }

        void MenuPrincipal::criarBotoes(){
            //const float posBotaoX = tamJanela.x / 2.0f - tamBotao.x / 2.0f;
            //addBotao("Jogar Floresta", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f), Estado::stateID::botao_novoJogo, sf::Color{0, 255, 0});
            //addBotao("Carregar Jogo", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 1.2f), Estado::stateID::botao_carregar_jogo, sf::Color{0, 255, 0});
            //addBotao("Colocacao", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 2.4f), Estado::stateID::botao_colocacao, sf::Color{0, 255, 0});
            //addBotao("Jogar Lava", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 3.6f), Estado::stateID::botao_opcao, sf::Color{0, 255, 0});
            //addBotao("Sair", sf::Vector2f(posBotaoX, tamJanela.y / 2.0f + tamBotao.y * 4.8f), Estado::stateID::botao_sair, sf::Color{0, 255, 0});
           // inicializarIterator();
            
        }

        void MenuPrincipal::executar(){
            //conteúdo do efeito Parallax
           // posFundo = sf::Vector2f(posFundo.x /*+ pGrafico->getTempo()*/ * 80.0f, posFundo.y);
            //pGrafico->atualizarCamera(sf::Vector2f(posFundo.x + tamJanela.x / 2.0f, posFundo.y + tamJanela.y / 2.0f));
            //fundo.executar();
            //pGrafico->limpaJanela();

            //desenha todo o conteúdo do menu principal na tela
            //desenhar();
            //pGrafico->desenhaElemento(titulo);
        }

    }

