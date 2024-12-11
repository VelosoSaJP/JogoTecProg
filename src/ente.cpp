#include "../include/Ente.h"

int Ente :: cont (0);
Gerenciadores :: Gerenciador_Grafico*  Ente  ::  pGG (NULL);
Gerenciadores :: Gerenciador_Eventos*  Ente  ::  pGE (NULL);

Ente::Ente():
    id(cont++)
{
    setTexture();
    setSprite();
}

Ente :: ~Ente(){
    cont--;
}

void Ente :: setTexture(){
    pText= new sf :: Texture();
    //pText->loadFromFile("path"); 
}

void Ente ::  setSprite(){
    pSprite = new sf :: Sprite();
    pSprite->setTexture(*pText, false);
    pSprite->setPosition(sf::Vector2f(HEIGTH/2.0,WIDTH/2.0));
    //pSprite->setScale(); - tamanho do sprite
}

void Ente :: desenhar(){ //vai ser chamado no executar das herdadas
    pGG -> desenhar(pSprite);
}

//sprite é composto por imagem, posição, tamanho, textura e afins. A textura é a imagem (a foto do bonequinho).