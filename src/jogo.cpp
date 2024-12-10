#include "../include/Jogo.h"

Jogo :: Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
     pGE (Gerenciadores::Gerenciador_Eventos::getInstancia())
{
}

Jogo :: ~Jogo(){}


void Jogo :: executar(){
    while (pGG->janelaAberta()){

        //gerenciador de eventos
        pGG->desenharEnte();
        pGG->display();
    }
}