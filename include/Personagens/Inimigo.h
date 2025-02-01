#pragma once
#include "Personagem.h"
#include "Jogador.h"
namespace Entidades{
namespace Personagens{
class Inimigo : public Personagem{
    private:
        int nivel_maldade;
        
    public:
    Inimigo(sf::Vector2f pos, sf::Vector2f tam, int ID);
    Inimigo();
    ~Inimigo();
    void andar(bool direita); //não vou levar para as classes filhas, porque todas vão se locomover do mesmo jeito.
    virtual void executar() = 0;
    virtual void salvar()=0;
    virtual void danificar(Jogador* p)=0;
    // void salvarDataBuffer();
};

}
}