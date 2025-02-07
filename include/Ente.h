#pragma once
#include <iostream>
#include "Gerenciadores/Gerenciador_Grafico.h"
#include "stdafx.h"

using namespace std;

class Ente{
protected:
    static Gerenciadores ::  Gerenciador_Grafico*  pGG;
    int id;
   
public:
Ente(); 
Ente(int ID); 
~Ente();
virtual void executar () = 0;
const int getID() const;

};