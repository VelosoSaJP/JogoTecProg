#include "../../include/Fases/Fase.h"

namespace Fases{
    
Fase :: Fase():
pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
pLE (new Lista::ListaEntidade())
{


}
Fase :: ~Fase(){
    delete pLE; //isso vai pra destrutora e limpa tudo.
    pGG = nullptr;
    pGE = nullptr;
    // devo deletar pGG e pGE aqui?

}


    
void Fase ::executar(){
    pGG->atualizaDeltaTime();        
    pGE->executar();
    pLE->percorrer();
}

void Fase::criarJogadores(int jog,sf::Vector2f posicao, sf::Vector2f tamanho){
    if(jog==1){
       
        Entidades::Personagens::Jogador *pJog1 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1));
        pJog1->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Jogador1/guerreiro.png");
        pLE->incluir(static_cast<Entidades::Entidade*>(pJog1));
    }
    else{
        Entidades::Personagens::Jogador *pJog2 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1));
        pJog2->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Jogador2/guerreira.png");
        pLE->incluir(static_cast<Entidades::Entidade*>(pJog2));

    }
}

void Fase::gerenciarColisoes(){}

}

   

