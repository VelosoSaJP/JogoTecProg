#pragma once
#include "Entidade.h"


namespace Entidades{
namespace Personagens{
class Personagem : public Entidade{
protected:
    int num_vidas;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, int ID);
    ~Personagem();      
    // salvarDataBuffer();
    virtual void salvar()=0;
    virtual void executar()=0;
    virtual void andar(bool direita);
    virtual void desenhar()=0;

    int const getVidas();
     virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;

};
}
}