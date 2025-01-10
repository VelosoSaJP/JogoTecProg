#include "Jogo.h"

Jogo::Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
     pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
     pJog1(NULL)
{
    // srand(time(NULL)); será útil para escolher aleatoriamente a posição dos entes, talvez seja melhor colocar em fase.h
    pJog1 = new Entidades::Personagens::Jogador(sf::Vector2f (300,150), sf::Vector2f (0.1,0.1));
}

Jogo::~Jogo(){
//os ponteiros foram aterrados nas destrutoras das respectivas classes
    delete pGE;
    delete pGG;
    delete pJog1;

    

}


void Jogo::executar(){
    while (pGG->janelaAberta()){
        
        pGG->limpaJanela();
                
        pGE->executar();
        // pLista->percorrer();
        pJog1->desenhar();
        //pGG->desenhar(Ente::)
        //gerenciador de eventos
        pGG->display();
    }
    printf("Janela fechada!\n");
}
