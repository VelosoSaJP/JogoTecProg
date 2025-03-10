#include "../../include/Fases/Fase.h"

namespace Fases{
    
Fase :: Fase():
pGG (Gerenciadores::Gerenciador_Grafico::getInstancia()),
pGE (Gerenciadores::Gerenciador_Eventos::getInstancia()),
pGEntradas(Gerenciadores::Gerenciador_Entradas::getInstancia()),
pLEPersonagens(nullptr),
pLEEstaticas(nullptr),
pMago(nullptr),
pGColisor(Gerenciadores::Gerenciador_Colisoes::getInstancia())

{
  pLEPersonagens=new Lista::ListaEntidade();
  pLEEstaticas=new Lista :: ListaEntidade();
  pMago= new Entidades::Personagens::Mago();
  

}

Fase :: ~Fase(){
    if(pLEPersonagens){
        delete pLEPersonagens; //isso vai pra destrutora e limpa tudo.
       
        if(pLEEstaticas){
            delete pLEEstaticas;
        }
            if(pMago){
                delete pMago;
            }
    }
    pGG = nullptr;
    pGE = nullptr;
    pGEntradas=nullptr;
    pGColisor=nullptr;


}


     
void Fase ::executar(){
    if (pGG)
    {
        pGG->atualizaDeltaTime();        
    
        if(pGColisor && pMago)
        {
              pGColisor->setListas(pLEPersonagens,pLEEstaticas);
              pMago->setLista(pLEPersonagens);
           
            if (pGE)
            {
                pGE->executar();
                if (pLEEstaticas != NULL)
                {
                   pLEEstaticas->percorrer();
                    if(pLEPersonagens != NULL)
                    {
                        pGG->carregarMapa(getCaminhoMapa());
                        pLEPersonagens->percorrer();
                    }

                } 
            }
            
        }
    }
    if(pGColisor){
        pGColisor->executar();
    }
}

void Fase::criarJogadores(int jog,sf::Vector2f posicao, sf::Vector2f tamanho){
    if(jog==1){
          Entidades::Personagens::Jogador *pJog1 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1), idJOGADOR,10000);
          pJog1->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Jogador1/guerreiro.png");
          pGEntradas->setJogador1(pJog1);
          pLEPersonagens->incluir(static_cast<Entidades::Entidade*>(pJog1));
        
       
    }
    else if(pGEntradas->getEhDois()){
         Entidades::Personagens::Jogador *pJog2 = new Entidades::Personagens::Jogador(posicao,  sf::Vector2f(0.1,0.1), idJOGADOR,10000);
         pJog2->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Jogador2/guerreira.png");
         pGEntradas->setJogador2(pJog2);
         pLEPersonagens->incluir(static_cast<Entidades::Entidade*>(pJog2));

    }
}

void Fase::criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho,int id){
        posicao.y+=5;
        Entidades::Obstaculos::Plataforma* pPlataforma = new Entidades::Obstaculos::Plataforma(posicao,sf::Vector2f(1,1),idPLATAFORMA); 
        pPlataforma->setTextura("/home/murilo/code/JogoTecProg/assets/Fases/Fase2/Tiles_rock/tile5.png");
        pPlataforma->executar();
        pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pPlataforma));
    
}

void Fase::gerenciarColisoes(){}

}


