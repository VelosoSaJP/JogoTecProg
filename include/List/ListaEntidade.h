#pragma once

/*#include "../Entidades/Entidade.h"
#include "List/Lista.h"*/

namespace Lista{

    class ListaEntidade
    {
    private:
        
        Lista<Entidade> LEs;

    public:
        ListaEntidade();
        
        ~ListaEntidade();

        void incluir(Entidade* pE);

        

    };
    

}//namespace Lista


