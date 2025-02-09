#include "../include/Gerenciadores/Gerenciador_Grafico.h"

namespace Gerenciadores{
Gerenciador_Grafico* Gerenciador_Grafico :: instancia(NULL);


Gerenciador_Grafico* Gerenciador_Grafico ::getInstancia(){
    if (instancia == NULL){
        instancia = new Gerenciador_Grafico();
    }
        return instancia;
}

Gerenciador_Grafico :: Gerenciador_Grafico():
   pJanela(NULL)
{
    setVideoMode();
    setJanela();
}

Gerenciador_Grafico :: ~Gerenciador_Grafico(){

        pJanela=NULL;
        delete instancia;
}

bool Gerenciador_Grafico :: janelaAberta() const{
    if(pJanela){
        return pJanela->isOpen();
    }
    return false;
}

void Gerenciador_Grafico :: setJanela(){
    pJanela = new sf::RenderWindow(videoMode, "Idade Media++");
}

void Gerenciador_Grafico :: setVideoMode(){
    videoMode.height=HEIGTH;
    videoMode.width=WIDTH;
}

sf::RenderWindow*  Gerenciador_Grafico :: getJanela () const{
    if(pJanela){
        return pJanela;
    }
}

void Gerenciador_Grafico :: limpaJanela(){
    if(pJanela){
     pJanela->clear();
    }
}

void Gerenciador_Grafico :: fechaJanela(){
    if(pJanela){
        pJanela->close();
    }
}


bool Gerenciador_Grafico :: eventoJanela(sf::Event& evento){ //ref escondida
    if(pJanela){
        return (pJanela->pollEvent(evento));
    }
    else{
        return 0;
    }
}

//Irá projetar em tela ente, menu e fases.
void  Gerenciador_Grafico :: desenhar(sf::Sprite* pS) const{
    if(pS && pJanela){
        pJanela->draw(*pS); //conteúdo apontado por pS;
    }
}

void Gerenciador_Grafico :: display(){
    if(pJanela){
        pJanela->display();
    }
}

const float Gerenciador_Grafico::getDeltaTime()const{
    return delta_time;
}

void Gerenciador_Grafico::atualizaDeltaTime(){
    delta_time = clock.restart().asMilliseconds();
}

void Gerenciador_Grafico::carregarMapa(string caminhoMapa){
   //cout<<"entre carregarmapa"<<endl;
    sf::Texture mapaTexture;
    sf::Sprite mapaSprite;
    
    mapaTexture.loadFromFile(caminhoMapa);

    mapaSprite.setTexture(mapaTexture);
    pJanela->draw(mapaSprite);

}

void Gerenciador_Grafico :: desenhar(sf::RectangleShape colisao) const{
    pJanela->draw(colisao);
}

void Gerenciador_Grafico::desenhaElemento(sf::RectangleShape corpo){
    pJanela->draw(corpo);
    }

void Gerenciador_Grafico::desenhaElemento(sf::Text texto){
    pJanela->draw(texto);
    }
void Gerenciador_Grafico::desenhaElemento(sf::Sprite fundo){
    pJanela->draw(fundo);
}

}

