#pragma once
#include "Ente.h"
#include <math.h>
namespace Entidades {
class Entidade : public Ente {
protected:
        //std::ostream& buffer; //ostream para saída de dados.
        float gravidade;
        float altura_pulo;
        sf::Vector2f velocidade;
        sf::Vector2f tamanho;
        sf::Vector2f posicao;
        sf::Sprite* pSprite; //equivalente ao Figura*
        sf::Texture* pText;
   
public:
Entidade();
Entidade(sf::Vector2f pos, sf::Vector2f tam, int ID);
~Entidade();


void setTextura(const char* caminhoTextura);
void setSprite();
void desenhar();

void efeitoGravidade();
virtual void andar(bool direita);
sf::Vector2f getVelocidade()const;
void setVelocidade(sf::Vector2f vel);
sf::Sprite*  getSprite() const;
sf::Vector2f  getTamanho() const;
sf::Vector2f getPosicao() const;
void setPosicao(sf::Vector2f pos);
virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
void setTamanho(sf::Vector2f tam);
virtual void empuxo();

virtual void executar() = 0;
virtual void salvar()=0; 
/*útil para pegar a posição da entidade para fins de mudança/movimento.Acessa o Ente e busca a postion do sprite*/
};
}