#include "../../../include/Menu/Botao/Botao.h"


    namespace Menu {

        namespace Botao {

            Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const Estado::stateID ID, const sf::Vector2f tamMax):
                Ente(ID), posBotao(pos), tamBotao(tam), textura(new sf::Texture()), tamMax(tamMax == sf::Vector2f(0.0f, 0.0f) ? tam : tamMax),
                 tamInicial(tam), aumentando(true)
            {
                caixa.setPosition(pos);
                caixa.setSize(tam);
            }

            Botao::~Botao(){
                if(textura){
                    delete(textura);
                    textura = nullptr;
                }
            }

            const sf::Vector2f Botao::getPos() const{
                return caixa.getPosition();
            }

            void Botao::setTextura(sf::Texture* textura){
                this->textura = textura;
                caixa.setTexture(textura);
            }

            void Botao::desenhar(){
                pGrafico->desenhaElemento(caixa);
            }

         
            }

        }

    

