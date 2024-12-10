#include"Lista.h"
#pragma once

/*#include "../Entidades/Entidade.h"
#include "List/Lista.h"*/

namespace Lista{

    class ListaEntidade
    {
    private:
        
        Lista <Entidade::Entidade> LEs;

    public:
        ListaEntidade();
        
        ~ListaEntidade();

        void incluir(Entidade* pE);

        void percorrer();

    };
    

}//namespace Lista


