#include "../include/List/ListaEntidade.h" 
#include "../include/Entidade.h" 

namespace Lista{

    ListaEntidade::ListaEntidade(){}

    ListaEntidade::~ListaEntidade(){
        //LEs.clear(); TERMINAR
    }

    void ListaEntidade::incluir(Entidades::Entidade* pE){
        if(pE){
            // LEs.push(pE); TERMINAR
        }
           
        else
            std::cout<<"Sem ponteiro entidadade para dar push"<< std::endl;

    }

    void ListaEntidade::percorrer(){
        //???????????????? percorre todos e chama o metodo executar deles
    }

}//namespace Lista
