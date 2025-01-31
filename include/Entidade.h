#pragma once
#include "Ente.h"

namespace Entidades {
class Entidade : public Ente {
protected:
        // float x;
        // float y;
        //std::ostream& buffer; //ostream para saída de dados.
        float gravidade;
public:
Entidade();
Entidade(sf::Vector2f pos, sf::Vector2f tam);
~Entidade();
virtual void executar() = 0; //ERA PARA SER VIRTUAL AQUI HEIN
const sf::Vector2f getPosicao()/*const*/; 
virtual void mover()=0;
virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
virtual void salvar()=0; 
/*útil para pegar a posição da entidade para fins de mudança/movimento.Acessa o Ente e busca a postion do sprite*/
};
}