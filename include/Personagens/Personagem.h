#pragma once
#include "Entidade.h"


namespace Entidades{
namespace Personagens{
class Personagem : public Entidade{
protected:
    int num_vidas;
    sf::RectangleShape desenhaColisao;
    
public:
    Personagem();
    Personagem(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida);
    ~Personagem();      
    // salvarDataBuffer();
    virtual void salvar()=0;
    virtual void executar()=0;
    virtual void andar(bool direita);
    virtual void desenhar()=0;
    virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
    void hitbox();
    virtual void empuxo();
    virtual bool getPodeSaltar();
    virtual void setPodeSaltar(bool permissao);
    void setVida(int vida);
    int getVida();

};
}
}