#include "../include/Ente.h"
Gerenciadores :: Gerenciador_Grafico* Ente:: pGG = Gerenciadores ::Gerenciador_Grafico :: getInstancia();

Ente::Ente(){

}

Ente :: Ente(int ID):
    id(ID)
{
}

Ente :: ~Ente(){
    pGG=NULL;
}

const int Ente :: getID() const{
    return id;
}

