#pragma once
//#include "../Ente.h"
//#include "../Jogador.h"
#include <SFML/Graphics.hpp>

namespace Gerenciadores{
class Gerenciador_Entradas{
private:
    //Personagens::Jogador* pJ;
    static Gerenciador_Entradas* instancia;

private:
Gerenciador_Entradas();
public:
~Gerenciador_Entradas();
Gerenciador_Entradas* getInstancia() const;
void teclaApertada(sf::Keyboard::Key tecla);
void teclaLiberada(sf::Keyboard::Key tecla);

};
}