#include "../include/Jogo.h"

Jogo :: Jogo():
    pjog1(NULL),
    GG()
{

}
Jogo :: ~Jogo(){

}
void Jogo :: executar(){
    while (GG.getWindow.isOpen()){
        //gerenciador de eventos

        GG.desenharEnte();
        GG.getWindow.display();
    }
}