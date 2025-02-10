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
    virtual void salvar()=0;
    virtual void executar()=0;
    virtual void andar(bool direita);
    virtual void desenhar()=0;
    virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
    void hitbox();
    virtual void empuxo();
    bool checarMorte();
    void tomarDano(int dano_sofrido);
    int getVida();
    

};
}
}