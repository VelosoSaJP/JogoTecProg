#include <iostream>

namespace Gerenciadores{
class Gerenciador_Eventos{
private:
static Gerenciador_Eventos* instancia;

private:
Gerenciador_Eventos();

public:
Gerenciador_Eventos* getInstancia() const;
~Gerenciador_Eventos();


};
}