#include "../../include/Fases/Fase.h"

namespace Fases{
    
Fase :: Fase():
pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
pGEntradas(Gerenciadores::Gerenciador_Entradas::getInstancia()),
pLEPersonagens(new Lista::ListaEntidade()),
pLEEstaticas(new Lista :: ListaEntidade()), listaPersonagens(new Lista::ListaEntidade()), listaObstaculos(new Lista::ListaEntidade()),
pGColisor(new Gerenciador_Colisoes(listaPersonagens, listaObstaculos))
//pGColisor()
{

}
Fase :: ~Fase(){
    delete pLEPersonagens; //isso vai pra destrutora e limpa tudo.
    delete pLEEstaticas;
    pGG = nullptr;
    pGE = nullptr;
    // devo deletar pGG e pGE aqui?

}


     
void Fase ::executar(){
    pGG->atualizaDeltaTime();        
    pGE->executar();
    // pLEEstaticas->checar(); TEM QUE CRIAR ESTE MÉTODO LÁ EM LISTA DE ENTIDADES.
    pLEPersonagens->percorrer();
    
    if(pGColisor){
    //printf("criou fi\n");
    //pGColisor->executar();//aqui ta dando seg fault

    }
}

void Fase::criarJogadores(int jog,sf::Vector2f posicao, sf::Vector2f tamanho){
    if(jog==1){
       
        Entidades::Personagens::Jogador *pJog1 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1), idJOGADOR);
        pJog1->setTextura("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Bonecos/Jogador1/guerreiro.png");
        pGEntradas->setJogador1(pJog1);
        pLEPersonagens->incluir(static_cast<Entidades::Entidade*>(pJog1));
    }
    else{
        Entidades::Personagens::Jogador *pJog2 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1), idJOGADOR);
        pJog2->setTextura("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Bonecos/Jogador2/guerreira.png");
        pGEntradas->setJogador2(pJog2);
        pLEPersonagens->incluir(static_cast<Entidades::Entidade*>(pJog2));

    }
}
void Fase::criarPlataforma(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    Entidades::Obstaculos::Pedra* pPlataforma = new Entidades::Obstaculos::Pedra(posicao,tamanho,idOBSTACULO);
    pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pPlataforma));
}

void Fase::gerenciarColisoes(){}

}



