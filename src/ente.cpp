#include "../include/Ente.h"

Ente::Ente():
    id(cont++)
    /*pFig(NULL),
    pGG(NULL)*/
{
}


Ente :: ~Ente(){
    cont--;
}

void desenhar();
