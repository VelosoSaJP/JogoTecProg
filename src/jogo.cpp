#include "Jogo.h"

//Gerenciador::GerenciadorEstado* Jogo::pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

Jogo::Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),pGEstado(Gerenciador::GerenciadorEstado::getGerenciadorEstado()),
     pGE(Gerenciadores::Gerenciador_Eventos::getInstancia())
{
    if(pGEstado == nullptr){
            std::cout << "ERROR::Principal::nao foi possivel criar um GerenciadorEstado" << std::endl;
            exit(1);
        }
        pEstadoJogar = new Estado::EstadoJogar();
}

Jogo::~Jogo(){
    if(pGG){
        delete pGG;
    }
    if(pGE){
        pGE=nullptr;//deixando para a própria classe Ger ESt deleter o ponteiro
    }

}


void Jogo::executar(){

    if(pGEstado){
        pGEstado->addEstado(Estado::stateID::menuPrincipal);
    }else{
        std::cerr<<"Nao criou pGEstado em jogo.cpp"<<std::endl;
    } 

    while (pGG->janelaAberta()){
        
        pGG->limpaJanela();
      
        pGE->executar();

        pGEstado->executar();
       
        pGG->display();
        
      
    }
    printf("Janela fechada!\n");
}
