#include "Gerenciador_Entradas.h"

namespace Gerenciadores{
Gerenciador_Entradas* Gerenciador_Entradas :: instancia(nullptr);

Gerenciador_Entradas* Gerenciador_Entradas :: getInstancia() const{
    if (instancia == NULL){
        instancia = new Gerenciador_Entradas();
    }
        return instancia;
}

Gerenciador_Entradas::Gerenciador_Entradas()//:
    //pJ(nullptr)
{

}

Gerenciador_Entradas:: ~Gerenciador_Entradas(){
    //delete pJ;//é isso msm?
}

void Gerenciador_Entradas:: teclaApertada(sf::Keyboard::Key tecla){
    //ideia- if (pJ->buscar a id do jogador) (quando for 2P)
    if (tecla == sf::Keyboard::A){}
    if (tecla == sf::Keyboard::W){}
    if (tecla == sf::Keyboard::S){}
    if (tecla == sf::Keyboard::D){}
}

void Gerenciador_Entradas:: teclaLiberada(sf::Keyboard::Key tecla){}
}