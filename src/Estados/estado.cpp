#include "../../include/Estado/Estado.h"
#include "../../include/Estado/MaquinaEstado.h"

namespace Estados{

   Estado::Estado(MaquinaEstados* pMaqEstado, Estados::IDestado ID) 
    : pMaqEstado(pMaqEstado), id(ID) 
    {

    }
    
    Estado::~Estado(){
        pMaqEstado = nullptr;
    }

    void Estado::setMaquinaEstado(MaquinaEstados* pMaqEstado){
        this->pMaqEstado = pMaqEstado;
    }

    void Estado::mudaEstado(Estados::IDestado novoEstado){
        pMaqEstado->mudaEstadoAtual(id);
    }

    IDestado Estado::getID() const{
        return id;
    }


}