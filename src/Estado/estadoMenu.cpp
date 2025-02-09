#include "../../include/Estado/EstadoMenu.h"
#include "../../include/Menu/MenuPrincipal.h"    //CRIAR MENUPRINCIPAL
#include "../../include/Gerenciadores/Gerenciador_Estado.h"


    namespace Estado {

        Gerenciador::GerenciadorEstado* EstadoMenu::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();       
        EstadoMenu::EstadoMenu(const stateID ID):
            Estado(ID),Ente(), menu(nullptr),/*pGG(Gerenciadores::Gerenciador_Grafico::getInstancia()),*/pGE(Gerenciadores::Gerenciador_Eventos::getInstancia()),
            opcoes(),fonte()
        {
            opcoes.clear();
            if(!fonte.loadFromFile("/usr/share/fonts/truetype/ubuntu/UbuntuMono-B.ttf"))
                cerr << "Erro ao carregar a fonte!" <<endl;
             // Carregar textura do fundo
            if (!texturaFundo.loadFromFile("/home/murilo/code/JogoTecProg/assets/fundo_menu.png")) { // Altere o caminho
                std::cerr << "Erro ao carregar textura de fundo!" <<endl;
            }
        
            // Configurar sprite do fundo
            fundo.setTexture(texturaFundo);
    
            criarMenu();
        }
        
        EstadoMenu::~EstadoMenu(){
            if(menu){
                delete(menu);
                menu = nullptr;
            }
        }
        
        Menu::Menu* EstadoMenu::getMenu(){
            return menu;
        }

        void EstadoMenu::criarMenu(){

          // Ajustar tamanho para janela (opcional)
        sf::Vector2u tamanhoJanela = pGG->getJanela()->getSize();
        fundo.setScale(
            tamanhoJanela.x / static_cast<float>(texturaFundo.getSize().x),
            tamanhoJanela.y / static_cast<float>(texturaFundo.getSize().y)
        );

            std::vector<std::string> textos = {
            "Menu Principal (Enter)",
            "Jogar Floresta (1)",
            "Jogar Lava (2)",
            "Sair (Esc)"
        };

         for (size_t i = 0; i < textos.size(); ++i) {
            sf::Text texto;
            texto.setFont(fonte);
            texto.setString(textos[i]);
            texto.setCharacterSize(20);
            texto.setPosition(150.f, 125.f + (i * 60.f));
            opcoes.push_back(texto);
        }
            //pGE->executar();
            // pGG->display();
            
            }

        void EstadoMenu::executar(){
            //menu->executar();
           /*
            sf::Font font;
            if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-R.ttf")) {
                exit(-1); // Erro ao carregar a fonte
            }
           */

            sf::Text titulo;
            titulo.setFont(fonte);
            titulo.setString("IDADE MEDIEVAL ++");
            titulo.setCharacterSize(35);
            titulo.setFillColor(sf::Color::Cyan);
            titulo.setStyle(sf::Text::Bold | sf::Text::Underlined);
            titulo.setPosition(120, 50);

            sf::Text adendo;
            adendo.setFont(fonte);
            adendo.setString("Pressione T para habilitar dois jogadores");
            adendo.setCharacterSize(20);
            adendo.setFillColor(sf::Color::White);
            adendo.setStyle(sf::Text::Bold);
            adendo.setPosition(280, 350);

            pGG->desenhaElemento(fundo);

            pGG->desenhaElemento(adendo);
            //pGG->limpaJanela();
            pGG->desenhaElemento(titulo);
            
            for(auto& opcao : opcoes)
             {
                pGG->desenhaElemento(opcao);
        }

        }

    }

