#include "../../include/Estado/EstadoJogar.h"

#include "../../include/Fases/Floresta.h"
#include "../../include/Fases/Lava.h"
#include "../../include/Fases/Fase.h"

    namespace Estado {


        EstadoJogar::EstadoJogar(){}

        EstadoJogar::EstadoJogar(const stateID ID):
            Estado(ID), //mapFase(), 
            ID_FaseAtual(ID)
        {
            if(ID == jogar_floresta){
                //pFaseFloresta = new Fases::Floresta();
                pFase = new Fases::Floresta();
                //pFase->criarFase();
               // if(pGGrafico && pFaseFloresta){
                //pGGrafico->carregarMapa("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Fases/Fase1/Fase1.png");
            }
            
            else if(ID == jogar_lava){
                //pFaseLava = new Fases::Lava();
                pFase = new Fases::Lava();


            }
            else{

                cout<<"ID não reconhecido EstadoJogar()"<<endl;
            }
        
        }
        EstadoJogar::~EstadoJogar(){
          /* std::map<IDs::IDs, Fase::Fase*>::iterator it = mapFase.begin();
           Fases::Fase* fase = it->second;
            while(it != mapFase.end()){
                fase = it->second;
                if(fase != nullptr){
                    delete(fase);
                    fase = nullptr;
                }
                it++;
            }
            mapFase.clear();
            pGrafico->setLimiteCamera(sf::IntRect(-1,-1,-1,-1));
            pGrafico->setLimiteObjeto(sf::IntRect(-1,-1,-1,-1));
                */
                pFaseFloresta = nullptr;
                pFaseLava = nullptr;
        }

        /*
        void EstadoJogar::criarFase(const std::string arquivoEntidades, std::vector<std::string> vectorInfoFase){
            Gerenciador::GerenciadorArquivo GArquivo;
            std::vector<std::string> salvarEntidades = GArquivo.lerArquivo(arquivoEntidades.c_str());
            std::vector<std::string> salvarEntidadesAux;
            Fases::Fase* fase = nullptr;
            int i = 0;
            while(i < salvarEntidades.size()){
                std::string linha = salvarEntidades[i];
                if(linha.find("=") != -1){
                    int id = std::stoi(linha.substr(0, linha.find(' ') + 1));
                    linha = linha.erase(0, linha.find(' ') + 1);
                    sf::IntRect limiteCamera;
                    limiteCamera.left = std::stoi(linha.substr(0, linha.find(' ') + 1));
                    linha = linha.erase(0, linha.find(' ') + 1);
                    limiteCamera.width = std::stoi(linha.substr(0, linha.find(' ') + 1));
                    linha = linha.erase(0, linha.find(' ') + 1);
                    limiteCamera.top = std::stoi(linha.substr(0, linha.find(' ') + 1));
                    linha = linha.erase(0, linha.find(' ') + 1);
                    limiteCamera.height = std::stoi(linha.substr(0, linha.find(' ') + 1));
                    switch (id)
                    {
                    case (53):
                    {
                        fase = static_cast<Fases::Fase*>(new Fases::FlorestaBranca(salvarEntidadesAux, vectorInfoFase, IDs::IDs::floresta_branca_parte_1));
                        mapFase.insert(std::pair<IDs::IDs, Fase::Fase*>(IDs::IDs::floresta_branca_parte_1, fase));
                        if(this->ID_FaseAtual == IDs::IDs::vazio){
                            this->ID_FaseAtual = IDs::IDs::floresta_branca_parte_1;
                        }
                    }
                        break;
                    case(54):
                    {
                        fase = static_cast<Fases::Fase*>(new Fases::FlorestaBranca(salvarEntidadesAux, vectorInfoFase, IDs::IDs::floresta_branca_parte_2));
                        mapFase.insert(std::pair<IDs::IDs, Fases::Fase*>(IDs::IDs::floresta_branca_parte_2, fase));
                        if(this->ID_FaseAtual == IDs::IDs::vazio){
                            this->ID_FaseAtual = IDs::IDs::floresta_branca_parte_2;
                        }
                    }
                        break;
                    case(55):
                    {
                        fase = static_cast<Fases::Fase*>(new Fases::FlorestaBranca(salvarEntidadesAux, vectorInfoFase, IDs::IDs::floresta_branca_parte_3));
                        mapFase.insert(std::pair<IDs::IDs, Fases::Fase*>(IDs::IDs::floresta_branca_parte_3, fase));
                        if(this->ID_FaseAtual == IDs::IDs::vazio){
                            this->ID_FaseAtual = IDs::IDs::floresta_branca_parte_3;
                        }
                    }
                        break;
                    default:
                        std::cout << "EstadoJogar::Erro ao criar fase, pois o Id atual eh invalido" << std::endl;
                        exit(1);
                        break;
                    }
                    fase->setLimiteCamera(limiteCamera);
                    fase = nullptr;
                    salvarEntidadesAux.clear();
                } else {
                    salvarEntidadesAux.push_back(linha);
                }
                i++;
            }
            fase = mapFase[this->ID_FaseAtual];
            pGrafico->setLimiteCamera(fase->getLimiteCamera());
            Entidade::Personagem::Jogador::Jogador* pJogador = fase->getJogador();
            if(pJogador != nullptr){
                pGrafico->atualizarCamera(pJogador->getPos(), pJogador->getTam());
                pJogador = nullptr;
            }
            fase = nullptr;
        }
        */
       /*
        void EstadoJogar::criarFase(){
            if(ID == IDs::IDs::jogar_florestaBranca){
                Fases::Fase* fase = static_cast<Fases::Fase*>(new Fase::FlorestaBranca());
                this->ID_FaseAtual = IDs::IDs::floresta_branca_parte_1;
                mapFase.insert(std::pair<IDs::IDs, Fase::Fase*>(ID_FaseAtual, fase));
            }
        }
        */
       /*
        std::map<IDs::IDs, Fase::Fase*> EstadoJogar::getMapFase(){
            return mapFase;
        }
        */
        const stateID EstadoJogar::getIDFaseAtual() const{
            return ID_FaseAtual;
        }
       /*
        */
       /*
        Fase::Fase* EstadoJogar::getFase(){
            return mapFase[ID_FaseAtual];
        }
        void EstadoJogar::mudarFase(const IDs::IDs ID_Fase){
            std::map<IDs::IDs, Fase::Fase*>::iterator it = mapFase.begin();
            const IDs::IDs ID_Fase_Anterior = this->ID_FaseAtual;
            while(it != mapFase.end()){
                if(it->second != nullptr){
                    if(it->first == ID_Fase){
                        mapFase[ID_FaseAtual]->removerJogadorLista();
                        this->ID_FaseAtual = ID_Fase;
                        mapFase[ID_FaseAtual]->mudarFase(ID_Fase_Anterior);
                        break;
                    }
                }
                it++;
            }
            if(this->ID_FaseAtual != ID_Fase){
                mapFase[ID_FaseAtual]->removerJogadorLista();
                this->ID_FaseAtual = ID_Fase;
                Fase::Fase* fase = static_cast<Fase::Fase*>(new Fase::FlorestaBranca(this->ID_FaseAtual));
                mapFase.insert(std::pair<IDs::IDs, Fase::Fase*>(ID_FaseAtual, fase));
                mapFase[ID_FaseAtual]->mudarFase(ID_Fase_Anterior);
            }
        }
        */
        /*
        void EstadoJogar::mudarEstadoObservador(){
            //desativa o observador do jogador
            Fases::Fase* fase = mapFase[ID_FaseAtual];
            Entidade::Personagem::Jogador::Jogador* jogador = fase->getJogador();
            if(jogador){
                fase->getJogador()->mudarEstadoObservador();
            }

            //desativa o observador da fase
            fase->mudarEstadoObservador();
        }
        */

         void EstadoJogar::executar(){
            //mapFase[ID_FaseAtual]->executar();
            // tem que ter um fase-> executar aqui 
            //mas o que pensei em fzr eh chamar o get estado do gerenciador e dai executar cada fase indvidual
            pFase->executar();
        }
    }
        
    
//    }

