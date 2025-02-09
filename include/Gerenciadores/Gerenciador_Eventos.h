#pragma once
#include <iostream>
//#include "Ente.h"
//#include "Gerenciador_Entradas.h"
#include "Gerenciador_Grafico.h"


namespace Gerenciadores {
    class Gerenciador_Entradas; // Declaração antecipada
}

namespace Gerenciadores{
class Gerenciador_Eventos{
private:
    static Gerenciador_Eventos* instancia;
    static Gerenciador_Grafico* pGG;
    static Gerenciador_Entradas* pGE;


private:
    Gerenciador_Eventos();

public:
static Gerenciador_Eventos* getInstancia();
~Gerenciador_Eventos();
void executar();




};
}