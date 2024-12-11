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
    setJanela();
    setVideoMode();
    //executar();
}
Gerenciador_Grafico :: ~Gerenciador_Grafico(){
    delete pJanela;
    pJanela=NULL;
}

bool Gerenciador_Grafico :: janelaAberta() const{
    return pJanela->isOpen();
}

void Gerenciador_Grafico :: setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "Idade Média++");
}

void Gerenciador_Grafico :: setVideoMode(){
    videoMode.height=HEIGTH;
    videoMode.width=WIDTH;
}

sf::RenderWindow*  Gerenciador_Grafico :: getJanela () const{
    return pJanela;
}

void Gerenciador_Grafico :: fechaJanela(){
    pJanela->close();
}


bool Gerenciador_Grafico :: eventoJanela(sf::Event& evento){ //ref escondida
    return (pJanela->pollEvent(evento));
}


//Irá projetar em tela ente, menu e fases.
void  Gerenciador_Grafico :: desenhar(sf::Sprite* pS) const{
    if(pS){
        pJanela->draw(*pS); //conteúdo apontado por pS;
    }
}

void Gerenciador_Grafico :: display(){
    pJanela->display();
}

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
*/
