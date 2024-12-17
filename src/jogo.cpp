#include "../include/Jogo.h"

Jogo :: Jogo():
    pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
    pGE (Gerenciadores::Gerenciador_Eventos::getInstancia())
     
{

}

Jogo :: ~Jogo(){

    delete pGG;
    delete pGE;
    delete pJog1;
    pGE=nullptr;
    pGG=nullptr;
    pJog1 = nullptr;
    

}


void Jogo :: executar(){
    //loop principal 
    while (pGG->janelaAberta()){

        //gerenciador de eventos
        //pGG->desenhar(Ente::)
        //pGG->display();
    }
}