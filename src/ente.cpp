#include "../include/Ente.h"

int Ente :: cont (0);
Gerenciadores :: Gerenciador_Grafico*  Ente  ::  pGG (NULL);
Gerenciadores :: Gerenciador_Eventos*  Ente  ::  pGE (NULL);

Ente::Ente():
    id(cont++)
{

}

Ente :: ~Ente(){
    cont--;
}

void Ente :: desenhar(){ //vai ser chamado no executar das herdadas
    
    pGG -> desenharEnte(pFig);

}