#pragma once
//#include "../Ente.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#define HEIGTH 400 
#define WIDTH 750

namespace Gerenciadores{
class Gerenciador_Grafico{

private:

    sf::VideoMode videoMode;
    sf::RenderWindow* pJanela;
    static Gerenciador_Grafico* instancia;
    float delta_time;
    sf::Clock clock;

private:    
Gerenciador_Grafico(); //construtora private (para o singleton)


public:

~Gerenciador_Grafico();
static Gerenciador_Grafico* getInstancia();

//janela
bool janelaAberta() const;
void setJanela();
void limpaJanela();
sf::RenderWindow* getJanela () const;
void fechaJanela();
bool eventoJanela(sf::Event& evento);//chama Gerenciador de Eventos.


void setVideoMode();



void desenhar (sf::Sprite* pS) const ; //monitor Lucas Skora

const float getDeltaTime() const;
void atualizaDeltaTime();


void display();


};
}