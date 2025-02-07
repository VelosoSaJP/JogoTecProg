#include "../include/Entidade.h"
namespace Entidades{

Entidade:: Entidade(){

}
Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, int ID):
    Ente(ID),
    posicao(pos),
    tamanho(tam),
    gravidade(0.0001f),
    altura_pulo(5),
    velocidade(0.0f,0.0f)
{
    pText= new sf::Texture(); 
    pSprite = new sf::Sprite();   
}

Entidade:: ~Entidade(){
if(pSprite){
        delete pSprite;
        if(pText){
            delete pText;
        }  
    }
    pSprite=NULL;
    pText=NULL;
}

void Entidade::desenhar(){
    pGG->desenhar(pSprite);
}

void Entidade::setPosicao(sf::Vector2f pos){
    posicao=pos;
    pSprite->setPosition(posicao);
}

void Entidade::setSprite(){
    pSprite->setTexture(*pText); //(*pText, false)
    pSprite->setPosition(posicao);
    pSprite->setScale(tamanho);     
}

void Entidade ::setTamanho(sf::Vector2f tam){
    tamanho=tam;
}

void Entidade::setTextura(const char* caminhoTextura){
 try {
        if (!pText->loadFromFile(caminhoTextura)) {  // Verifica se o carregamento falhou
            throw std::runtime_error("Erro ao carregar a textura: " + std::string(caminhoTextura));
        }
        setSprite();
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }   
}

sf::Vector2f Entidade::getVelocidade()const{
    return velocidade;
}

void Entidade:: setVelocidade(sf::Vector2f vel){
    velocidade=vel;
}

void Entidade::efeitoGravidade(){
         velocidade.y += gravidade*pGG->getDeltaTime();
}   


sf::Vector2f Entidade::getTamanho() const{
    return tamanho;
}

sf::Sprite* Entidade::getSprite() const{
    if(pSprite){return pSprite;}
}

sf::Vector2f Entidade::getPosicao() const {
    if(pSprite){return pSprite->getPosition();}
}



void Entidade::andar(bool direita){}


}