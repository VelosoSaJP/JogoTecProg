#pragma once
#include "Personagem.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <math.h>
namespace Entidades{
namespace Personagens{

class Jogador : public Personagem{
private:
    int pontos;
    Gerenciadores::Gerenciador_Colisoes* pGC;
   
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID);
    ~Jogador();
    void executar();
    void atualizaPosicao();
    void desenhar();
    void salvar();
    void parar(bool salto);
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    void saltar();
    bool getPodeSaltar();
    void setPodeSaltar(bool permissao);
    void andar(bool direita);
    bool passivelDeMovimento(sf::Vector2f novaPosicao);

};

}
}
//lembrar que herda mover de personagem(entidade).