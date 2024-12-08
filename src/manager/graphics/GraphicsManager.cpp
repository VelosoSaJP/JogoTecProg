#include "../../../include/manager/GraphicsManager.h"

namespace Gerenciadores{

GraphicsManager :: GraphicsManager():
   pWindow(NULL)
{
    setVideoMode();
    setWindow();
    //executar();
}
GraphicsManager :: ~GraphicsManager(){
    delete pWindow;
    pWindow=NULL;
}

void GraphicsManager :: setWindow(){
    //Ao invés de criar uma variável, poderia só colocar as dimensões.
    pWindow = new sf::RenderWindow(videoMode, "Título");
}

void GraphicsManager :: setVideoMode(){
    videoMode.height=400;
    videoMode.width=750;
}

sf::RenderWindow* :: GraphicsManager :: getWindow () const{
    return pWindow;
}
//void GraphicsManager :: desenharEnte(Ente* pE){}

//void GraphicsManager :: executar (){}




}


/*  
  while(window.isOpen()){
        sf::Event evento;
        if (window.pollEvent(evento)){
            if(evento.type== sf::Event::Closed){
                window.close();
            }
        }
    }

////////////////////////////////////////

  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
*/