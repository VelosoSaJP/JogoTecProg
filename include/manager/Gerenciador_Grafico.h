#include "../Ente.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

namespace Gerenciadores{
class Gerenciador_Grafico{

private:

    sf::VideoMode videoMode;
    sf::RenderWindow* pJanela;
    static Gerenciador_Grafico* instancia;
    Gerenciador_Grafico(); //construtora private (para o singleton)


public:
~Gerenciador_Grafico();
Gerenciador_Grafico* getInstancia() const;

sf::RenderWindow* getJanela () const;

bool janelaAberta() const;
void setJanela();

void setVideoMode();
void desenharEnte(sf::Sprite* pS);
void display();


};
}