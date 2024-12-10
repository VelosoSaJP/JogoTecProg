#include "../../../include/manager/Gerenciador_Grafico.h"

namespace Gerenciadores{
Gerenciador_Grafico* Gerenciador_Grafico :: instancia(NULL);


Gerenciador_Grafico* Gerenciador_Grafico ::getInstancia() const{
    if (instancia == NULL){
        instancia = new Gerenciador_Grafico();
    }
        return instancia;
}

Gerenciador_Grafico :: Gerenciador_Grafico():
   pJanela(NULL)
{
    setVideoMode();
    setJanela();
    //executar();
}
Gerenciador_Grafico :: ~Gerenciador_Grafico(){
    delete pJanela;
    pJanela=NULL;
}

void Gerenciador_Grafico :: setJanela(){
    //Ao invés de criar uma variável, poderia só colocar as dimensões.
    pJanela = new sf::RenderWindow(videoMode, "Título");
}

void Gerenciador_Grafico :: setVideoMode(){
    videoMode.height=400;
    videoMode.width=750;
}

sf::RenderWindow*  Gerenciador_Grafico :: getJanela () const{
    return pJanela;
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