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


private:    
Gerenciador_Grafico(); //construtora private (para o singleton)


public:

~Gerenciador_Grafico();
Gerenciador_Grafico* getInstancia() const;

//janela
bool janelaAberta() const;
void setJanela();
sf::RenderWindow* getJanela () const;
void fechaJanela() ;
bool eventoJanela(sf::Event& evento);//chama Gerenciador de Eventos.


void setVideoMode();



void desenhar (sf::Sprite* pS) const ; //monitor Lucas Skora
void display();


};
}