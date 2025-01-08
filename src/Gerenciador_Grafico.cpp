#include "../include/manager/Gerenciador_Grafico.h"

namespace Gerenciadores{
Gerenciador_Grafico* Gerenciador_Grafico :: instancia(NULL);


Gerenciador_Grafico* Gerenciador_Grafico ::getInstancia(){
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

        pJanela=NULL;
}

bool Gerenciador_Grafico :: janelaAberta() const{
    if(pJanela){
        return pJanela->isOpen();
    }
}

void Gerenciador_Grafico :: setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "Idade Media++");
}

void Gerenciador_Grafico :: setVideoMode(){
    videoMode.height=HEIGTH;
    videoMode.width=WIDTH;
}

sf::RenderWindow*  Gerenciador_Grafico :: getJanela () const{
    if(pJanela){
        return pJanela;
    }
}

void Gerenciador_Grafico :: limpaJanela(){
    if(pJanela){
     pJanela->clear();
    }
}

void Gerenciador_Grafico :: fechaJanela(){
    if(pJanela){
        pJanela->close();
    }
}


bool Gerenciador_Grafico :: eventoJanela(sf::Event& evento){ //ref escondida
    if(pJanela){
        return (pJanela->pollEvent(evento));
    }
    else{
        return 0;
    }
}

//Irá projetar em tela ente, menu e fases.
void  Gerenciador_Grafico :: desenhar(sf::Sprite* pS) const{
    if(pS && pJanela){
        pJanela->draw(*pS); //conteúdo apontado por pS;
    }
}

void Gerenciador_Grafico :: display(){
    if(pJanela){
        pJanela->display();
    }
}

}

