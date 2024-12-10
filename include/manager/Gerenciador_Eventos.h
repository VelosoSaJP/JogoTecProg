#include <iostream>

namespace Gerenciadores{
class Gerenciador_Eventos{
private:
Gerenciador_Eventos();
static Gerenciador_Eventos* instancia;

public:
Gerenciador_Eventos* getInstancia() const;
~Gerenciador_Eventos();


};
}