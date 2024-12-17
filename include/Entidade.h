#include "Ente.h"
#pragma once

namespace Entidades {
class Entidade : public Ente{
protected:
        float x;
        float y;
        //std::ostream& buffer; //ostream para saída de dados.
public:
Entidade();
~Entidade();
virtual void executar()=0;
virtual void salvar()=0;
void salvarDataBuffer();
virtual float getPosition(); /*útil para pegar a posição
da entidade para fins de mudança/movimento.Acessa o Ente e busca a postion do sprite*/
};
}