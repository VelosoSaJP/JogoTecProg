#include <iostream>
#include "../Ente.h"
#include "Gerenciador_Entradas.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
//#include "Gerenciador_Entradas.h"
#pragma once

namespace Gerenciadores{
class Gerenciador_Eventos{
private:
    static Gerenciador_Eventos* instancia;
    Gerenciador_Grafico* pGG;
    Gerenciador_Entradas* pGE;

private:
    Gerenciador_Eventos();

public:
Gerenciador_Eventos* getInstancia() const;
~Gerenciador_Eventos();
void executar();


};
}