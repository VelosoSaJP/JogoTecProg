#include "Jogo.h"

Jogo::Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
     pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
    pJog1(new Entidades::Personagens::Jogador(sf::Vector2f (300,150), sf::Vector2f (0.1,0.1))),
    pObs(new Entidades::Obstaculos::Obstaculo(sf::Vector2f (200,150), sf::Vector2f (0.75,0.75))),
     pLE()
{

    // srand(time(NULL)); será útil para escolher aleatoriamente a posição dos entes, talvez seja melhor colocar em fase.h
    pLE = new Lista::ListaEntidade();
    pLE->incluir (static_cast<Entidades::Entidade*>(pObs));
    pLE->incluir(static_cast<Entidades::Entidade*>(pJog1));
}

Jogo::~Jogo(){
//os ponteiros foram aterrados nas destrutoras das respectivas classes
    delete pGE;
    delete pGG;
    delete pLE;
    delete pObs;
    delete pJog1;
}


void Jogo::executar(){
    while (pGG->janelaAberta()){
        
        pGG->limpaJanela();
                
        pGE->executar();

       pLE->percorrer();
        //é o desenhar de Ente
        //pJog1->desenhar();//vai para listaEntidades depois
        //pGG->desenhar(Ente ::)
        //gerenciador de eventos
        pGG->display();
    }
    printf("Janela fechada!\n");
}
