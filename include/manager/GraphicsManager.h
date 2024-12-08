#include "../Ente.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

namespace Gerenciadores{
class GraphicsManager{

private:
    sf::VideoMode videoMode;
    sf::RenderWindow* pWindow;

public:
GraphicsManager();
~GraphicsManager();

sf::RenderWindow* getWindow () const;


void setWindow();
void setVideoMode();

void desenharEnte(Ente* pE);

void executar ();

};
}