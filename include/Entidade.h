#include "Ente.h"

namespace Entidades {
class Entidade : public Ente{
private:
        float x;
        float y;
        ostream buffer; //ostream para saída de dados.
public:
Entidade();
~Entidade();
virtual void executar()=0;
virtual void salvar()=0;
void salvarDataBuffer();

};
}