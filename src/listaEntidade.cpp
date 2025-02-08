#include "../include/Listas/ListaEntidade.h" 
#include "Entidade.h" 

namespace Lista{

    ListaEntidade::ListaEntidade()
    {
        LEs.getInicio();
        
    }

    ListaEntidade::~ListaEntidade(){
        LEs.limpar();
    }

    void ListaEntidade::incluir(Entidades::Entidade* pE){
        if(pE){
            LEs.incluir(pE);
        }
        else{
            cout<<"Erro no ponteiro de entidade para incluir na lista"<< endl;
        }
    }

    void ListaEntidade::excluir (Entidades::Entidade* pE){
        if(pE){
            LEs.remover(pE);
        }
        else{
            cout<<"Erro no ponteiro de entidade para remover da lista"<< endl;
        }
    }

    void ListaEntidade::percorrer(){
         auto it = LEs.getInicio(); 
        
        for (int i=0; i< getTamanho(); i++){
            Entidades::Entidade* pPercorre = *it;
            if(pPercorre){
                if(pPercorre->getID()==2||pPercorre->getID()==3 || pPercorre->getID()==4){ //iD dos inimigos
                    pPercorre->andar(true);
                }
                    pPercorre->efeitoGravidade();
                
                    pPercorre->executar(); 
                    //CONFERIR SE JÁ DESENHA, CASO NÃO: pPercorre->desenhar();
            }
            ++it; //sobrecarga do operator.
        
        }
    }

    int ListaEntidade::getTamanho() const{
        return LEs.getTamanho();
    }

   Lista<Entidades::Entidade>& ListaEntidade::getLista() {
    if (LEs.getTamanho() > 0) {
        return LEs;
    } else {
        throw std::runtime_error("Lista vazia!");
    }
}


}