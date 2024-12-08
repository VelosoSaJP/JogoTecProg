#include "Entidade.h"

namespace Personagens {
class Personagem : public Entidades :: Entidade{
private:
    int num_vidas;
public:
    Personagem();
    ~Personagem();
    void salvarDataBuffer();
    virtual void mover();
    virtual void executar()=0;
};
}