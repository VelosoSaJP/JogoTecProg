#pragma once 
#include "../Inimigo.h"
#include "../Obstaculo.h"
#include "Jogador.h"
//#include "../Projetil.h"
#include<list>
namespace Gerenciadores {
class Gerenciador_Colisoes{
private:
    vector <Personagens::Inimigo*> inimigos;
    list <Obstaculos::Obstaculo*> obstaculos;
    //set <Projetil*> projeteis;
    Personagens::Jogador* pJog1;
    static Gerenciador_Colisoes* instancia;

private:
Gerenciador_Colisoes();

public:
Gerenciador_Colisoes* getInstancia() const;
~Gerenciador_Colisoes();
const bool verificarColisao(Entidades::Entidade* pE1,Entidades::Entidade* pE2);
void tratarColisoesJogsObstacs();
void tratarColisoesJogsInimgs();
void tratarColisoesJogsProjeteis();
void incluirInimigo(Personagens::Inimigo* pI);
void incluirObstaculo(Obstaculos::Obstaculo* pO);
//void incluir Projetil(Projetil* pJ);
void executar();


};

}