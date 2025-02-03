#include "../include/Ente.h"

int Ente :: cont (0);
Gerenciadores :: Gerenciador_Grafico* Ente:: pGG = Gerenciadores ::Gerenciador_Grafico :: getInstancia();

// Gerenciadores :: Gerenciador_Eventos*  Ente  ::  pGE (NULL);

Ente::Ente(){

}

Ente::Ente(sf::Vector2f pos, sf::Vector2f tam, sf ::Vector2f velocidade, int ID):
    id(ID),
    posicao(pos), //tam e pos passados de acordo com o ent em questão, dada a herança
    tamanho(tam)

{
    pText = new sf::Texture();
    pSprite = new sf::Sprite();
}

Ente :: ~Ente(){

    delete pSprite;
    delete pText;
    cont--; //SERÁ ÚTIL?
    pSprite=NULL;
    pText=NULL;
    pGG=NULL;
}

void Ente::setTextura(const char* caminhoTextura) {
    try {
        if (!pText->loadFromFile(caminhoTextura)) {  // Verifica se o carregamento falhou
            throw std::runtime_error("Erro ao carregar a textura: " + std::string(caminhoTextura));
        }
        setSprite();
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
}

void Ente::setSprite(){
    pSprite->setTexture(*pText); //(*pText, false)
    pSprite->setPosition(posicao);
    pSprite->setScale(tamanho); 
}
 

void Ente :: desenhar(){ //vai ser chamado no executar das herdadas
    pGG -> desenhar(pSprite);
}

//sprite é composto por imagem, posição, tamanho, textura e afins. A textura é a imagem (a foto do bonequinho).

const sf::Vector2f Ente::getVel() const{
    return velocidade;
}

const sf::Vector2f Ente::getTam() const{
    return tamanho;
}

void Ente::setPosicao(sf::Vector2f pos){
    posicao += pos ;
}

const int Ente:: getID() const{ return id; };
