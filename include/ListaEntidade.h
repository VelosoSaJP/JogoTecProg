#pragma once
#include"Lista.h"
#include"Entidade.h"

/*#include "../Entidades/Entidade.h"
#include "List/Lista.h"*/

namespace Lista{

    class ListaEntidade
    {
    private:
        
        Lista <Entidades::Entidade> LEs;

    public:
        ListaEntidade();
        
        ~ListaEntidade();

        void incluir(Entidades::Entidade* pE);

        void percorrer();

    };
    

}//namespace Lista


