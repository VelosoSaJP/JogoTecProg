#include "../include/manager/Gerenciador_Eventos.h"

namespace Gerenciadores{

Gerenciador_Eventos* Gerenciador_Eventos :: instancia(NULL);

Gerenciador_Eventos :: Gerenciador_Eventos(){

}

Gerenciador_Eventos :: ~Gerenciador_Eventos(){}


Gerenciador_Eventos* Gerenciador_Eventos ::  getInstancia() const{
    if (instancia == NULL){
        instancia = new Gerenciador_Eventos();
    }
        return instancia;
    
}
  
}