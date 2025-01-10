#pragma once
#include "Entidade.h"


namespace Entidades{
namespace Personagens{
class Personagem : public Entidade{
protected:
    int num_vidas;
    float velocidade;
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam);
    ~Personagem();      
    // salvarDataBuffer();
    // virutal void mover()=0;
    virtual void salvar()=0;
    virtual void executar()=0;
    int const getVidas();
};
}
}