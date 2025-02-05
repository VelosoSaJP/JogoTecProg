#pragma once
#include "Ente.h"
#include <math.h>
namespace Entidades {
class Entidade : public Ente {
protected:
        //std::ostream& buffer; //ostream para saída de dados.
        float gravidade;
        float altura_pulo;
public:
Entidade();
Entidade(sf::Vector2f pos, sf::Vector2f tam, int ID);
~Entidade();
virtual void executar() = 0; //ERA PARA SER VIRTUAL AQUI HEIN
const sf::Vector2f getPosicao()/*const*/; 
virtual void colisao(Entidade* outraEntidade,sf::Vector2f distancia)=0;
virtual void salvar()=0; 
void efeitoGravidade();
virtual void andar(bool direita);
/*útil para pegar a posição da entidade para fins de mudança/movimento.Acessa o Ente e busca a postion do sprite*/
};
}