#include "Jogo.h"
Jogo::Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
     pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
     pJog1(NULL)
{
    // srand(time(NULL)); será útil para escolher aleatoriamente a posição dos entes, talvez seja melhor colocar em fase.h

}

Jogo::~Jogo(){

    delete pGE;
    delete pGG;
    delete pJog1;

    

}


void Jogo::executar(){
    while (pGG->janelaAberta()){
        
        pGG->limpaJanela();
        pGG->display();
        
        // pGE->eventPool
        //gerenciador de eventos
        //pGG->desenhar(Ente::)
    }
}
