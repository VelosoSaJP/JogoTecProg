#pragma once 

#include "../../Ente.h"
#include "../../Estado/Estado.h"

    namespace Menu {

        namespace Botao {

            class Botao : public Ente {
                private:
                    const sf::Vector2f tamMax;
                    const sf::Vector2f tamInicial;
                    bool aumentando;

                protected:
                    sf::RectangleShape caixa;
                    sf::Texture* textura;
                    sf::Vector2f posBotao;
                    sf::Vector2f tamBotao;
                    Gerenciadores::Gerenciador_Grafico* pGrafico;   

//                  const float tempoTroca;
//                  float tempo;
                public:
                    Botao(const sf::Vector2f tam, const sf::Vector2f pos, const Estado::stateID ID,  const sf::Vector2f tamMax = sf::Vector2f(0.0f, 0.0f));
                    virtual ~Botao();
                    virtual void desenhar();
                    //virtual void atualizarAnimacao();
                    //virtual void atualizarPosicaoCaixa(const sf::Vector2f pos);
                    void setTextura(sf::Texture* textura);
                    const sf::Vector2f getPos() const;
            };

        }

    }

