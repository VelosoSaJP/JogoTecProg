#pragma once
#include "Personagem.h"
#include "Mago.h"
#include "Esqueleto.h"
#include "Orc.h"
#include <math.h>

namespace Gerenciadores {
    class Gerenciador_Colisoes; //forward declaration
}


namespace Entidades{
namespace Personagens{

class Jogador : public Personagem{
private:
    Gerenciadores::Gerenciador_Colisoes* pGC;
    bool pode_saltar;
   
public:
    Jogador();
    Jogador(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida);
    ~Jogador();
    void executar();
    void atualizaPosicao();
    void desenhar();
    void salvar();
    void parar(bool salto);
    void colisao(Entidade* outraEntidade,sf::Vector2f distancia);
    void saltar();
    void setPodeSaltar(bool permissao);
    void andar(bool direita);
    bool passivelDeMovimento(sf::Vector2f novaPosicao);

};

}
}
//lembrar que herda mover de personagem(entidade).