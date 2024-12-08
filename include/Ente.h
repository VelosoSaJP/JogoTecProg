#pragma once
#include <iostream>
using namespace std;

class Ente{
private:
    int id;
    static int cont;
    //static *Gerenciador_Grafico pGG;
    //Figura pFig;

public:
Ente();
~Ente();
virtual void executar () = 0;
void desenhar();

};

int Ente :: cont (0);