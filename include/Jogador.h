#include "Personagem.h"

namespace Personagens{
class Jogador : public Personagem{
private:
    int pontos;
public:
    Jogador();
    ~Jogador();
    void executar();

};
}