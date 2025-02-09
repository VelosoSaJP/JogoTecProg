#include "../include/Gerenciadores/Gerenciador_Entradas.h"
#include "../include/Gerenciadores/Gerenciador_Estado.h"

namespace Gerenciadores{
Gerenciador_Entradas* Gerenciador_Entradas :: instancia(nullptr);
Gerenciador_Grafico* Gerenciador_Entradas :: pGG = Gerenciador_Grafico::getInstancia();
//Gerenciador::GerenciadorEstado* pGEstado = Gerenciador::GerenciadorEstado::getGerenciadorEstado();

Gerenciador_Entradas* Gerenciador_Entradas :: getInstancia(){
    if (instancia == NULL){
        instancia = new Gerenciador_Entradas();
    }
        return instancia;
}

Gerenciador_Entradas::Gerenciador_Entradas():pGEstado(Gerenciador::GerenciadorEstado::getGerenciadorEstado())
{
    pJog1=nullptr;
    pJog2=nullptr;
    ehDois=false;

}

Gerenciador_Entradas:: ~Gerenciador_Entradas(){ //o jogador é destruído no limpar da lista entidades.
    delete instancia;
}
void Gerenciador_Entradas::setJogador1(Entidades::Personagens::Jogador* pJog){
    pJog1=pJog;
}

void Gerenciador_Entradas:: setJogador2(Entidades::Personagens::Jogador* pJog){
    pJog2=pJog;
}

void Gerenciador_Entradas:: teclaApertada(sf::Keyboard::Key tecla){

    if (tecla == sf::Keyboard::W){ 
        if(pJog2!=nullptr){pJog2->saltar();}
     }
    if (tecla == sf::Keyboard::A){
        if(pJog2!=nullptr){pJog2->andar(false);}
    }
  
    if (tecla == sf::Keyboard::D){
        if(pJog2!=nullptr){pJog2->andar(true);}
    }

     if (tecla == sf::Keyboard::Up){ 
        if(pJog1!=nullptr){pJog1->saltar();}
    }
  
    if (tecla == sf::Keyboard::Left){
        if(pJog1!=nullptr){pJog1->andar(false);}

    }
      if (tecla == sf::Keyboard::Right){ 
        if(pJog1!=nullptr){pJog1->andar(true);}

    }
    
    if(tecla == sf::Keyboard::Num1){
        if (pGEstado)
        {
            pGEstado->addEstado(Estado::stateID::jogar_floresta);
        }else cout<<"acontece nada fi"<<endl;
    }
    if(tecla == sf::Keyboard::Num2){
        if (pGEstado)
        {
            pGEstado->addEstado(Estado::stateID::jogar_lava);
        }else cout<<"aq tbm nao mofi"<<endl;
    }
    if(tecla == sf::Keyboard::Enter){
        pGEstado->addEstado(Estado::stateID::menuPrincipal);
    }

    if(tecla == sf::Keyboard::Escape){
        pGG->fechaJanela();
    }
    if(tecla == sf::Keyboard::T){
        if(getEhDois()){
            setEhDois(false);
        }
        else{
            setEhDois(true);
        }
    }
    
}

void Gerenciador_Entradas:: teclaLiberada(sf::Keyboard::Key tecla){

      if (tecla == sf::Keyboard::W){ 
         if(pJog2!=nullptr){pJog2->parar(true);}
     }
    if (tecla == sf::Keyboard::A){
        if(pJog2!=nullptr){pJog2->parar(false);}
    }
  
    if (tecla == sf::Keyboard::D){
        if(pJog2!=nullptr){pJog2->parar(false);}
    }

     if (tecla == sf::Keyboard::Up){ 
         if(pJog1!=nullptr){pJog1->parar(true);}
    }
  
    if (tecla == sf::Keyboard::Left){
        if(pJog1!=nullptr){pJog1->parar(false);}

    }
      if (tecla == sf::Keyboard::Right){ 
        if(pJog1!=nullptr){pJog1->parar(false);}

    }
}

void Gerenciador_Entradas::setEhDois(bool mudaJOG){
    ehDois = mudaJOG;
}

bool Gerenciador_Entradas::getEhDois(){
    return ehDois;
}

}