#include "Jogo.h"

Jogo::Jogo():
     pGG (Gerenciadores::Gerenciador_Grafico::getInstancia())
{


}

Jogo::~Jogo(){

    delete pGG;

}


void Jogo::executar(){
    
    //if(menu==1){
    Fases::Floresta* pFaseAtual = new Fases::Floresta();
    /*{else
    Fases::Lava* pFaseAtual = new Fases::Lava();
    }*/
   

    while (pGG->janelaAberta()){
        
        pGG->limpaJanela();
        pGG->carregarMapa(pFaseAtual->getCaminhoMapa());
        pFaseAtual->executar();
        pGG->display();
        
      
    }
    printf("Janela fechada!\n");
}
