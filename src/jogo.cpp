#include "../include/Jogo.h"

Jogo :: Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
     pGE (Gerenciadores::Gerenciador_Eventos::getInstancia())
{

}

Jogo :: ~Jogo(){

    srand(time(NULL));

    

}


void Jogo :: executar(){
    while (pGG->janelaAberta()){

        //gerenciador de eventos
        pGG->desenhar(Ente::)
        pGG->display();
    }
}