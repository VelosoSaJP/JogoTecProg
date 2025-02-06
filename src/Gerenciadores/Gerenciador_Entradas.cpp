#include "../include/Gerenciadores/Gerenciador_Entradas.h"

namespace Gerenciadores{
Gerenciador_Entradas* Gerenciador_Entradas :: instancia(nullptr);
Gerenciador_Grafico* Gerenciador_Entradas :: pGG = Gerenciador_Grafico::getInstancia();

Gerenciador_Entradas* Gerenciador_Entradas :: getInstancia(){
    if (instancia == NULL){
        instancia = new Gerenciador_Entradas();
    }
        return instancia;
}

Gerenciador_Entradas::Gerenciador_Entradas(){
    pJog1=nullptr;
    pJog2=nullptr;


}

Gerenciador_Entradas:: ~Gerenciador_Entradas(){ //o jogador é destruído no limpar da lista entidades.
    
}
void Gerenciador_Entradas::setJogador1(Entidades::Personagens::Jogador* pJog){
    pJog1=pJog;
}

void Gerenciador_Entradas:: setJogador2(Entidades::Personagens::Jogador* pJog){
    pJog2=pJog;
}

void Gerenciador_Entradas:: teclaApertada(sf::Keyboard::Key tecla){

      if (tecla == sf::Keyboard::W){ 
        if(pJog2!=nullptr){pJog2->saltar(pJog2);}
     }
    if (tecla == sf::Keyboard::A){
        if(pJog2!=nullptr){pJog2->andar(false);}
    }
  
    if (tecla == sf::Keyboard::D){
        if(pJog2!=nullptr){pJog2->andar(true);}
    }

     if (tecla == sf::Keyboard::Up){ 
        if(pJog1!=nullptr){pJog1->saltar(pJog1);}
    }
  
    if (tecla == sf::Keyboard::Left){
        if(pJog1!=nullptr){pJog1->andar(false);}

    }
      if (tecla == sf::Keyboard::Right){ 
        if(pJog1!=nullptr){pJog1->andar(true);}

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
}