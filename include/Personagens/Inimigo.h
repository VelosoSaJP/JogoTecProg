#pragma once
#include "Personagem.h"
#include "Jogador.h"
namespace Entidades{
namespace Personagens{
class Inimigo : public Personagem{
    private:
        float pos_inicialX;
        float tam_plataforma;
        bool direita;
    protected:
        int quantidade_dano;
        
    public:
    Inimigo(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida, int dano);
    Inimigo();
    ~Inimigo();
    void andar(bool direita); //não vou levar para as classes filhas, porque todas vão se locomover do mesmo jeito.
    virtual void executar() = 0;
    virtual void salvar()=0;
    virtual void desenhar()=0;
    virtual void danificar(Jogador* p)=0;
    virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
    virtual void empuxo();
    virtual void atacar(sf::Vector2f pos, sf::Vector2f tam, int ID);


    // void salvarDataBuffer();
};

}
}