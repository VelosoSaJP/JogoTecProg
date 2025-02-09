#include "../../include/Gerenciadores/Gerenciador_Estado.h"


    namespace Gerenciador {

        GerenciadorEstado* GerenciadorEstado::pGerenciadorEstado = nullptr;
        

        GerenciadorEstado::GerenciadorEstado():
            pilhaEstados()//,pEstadoAtual(Estado::Estado())
        {
            //pEstadoAtual = new Estado::Estado::Estado(Estado::stateID::unknown);
        }

        GerenciadorEstado* GerenciadorEstado::getGerenciadorEstado(){
            if(pGerenciadorEstado == nullptr){
                pGerenciadorEstado = new GerenciadorEstado();
            }
            return pGerenciadorEstado;
        }

        GerenciadorEstado::~GerenciadorEstado(){
            //deleta todos os estados da minha pilha
            while(!pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }


            if(pGerenciadorEstado){
                delete(pGerenciadorEstado);
                pGerenciadorEstado = nullptr;
            }
        }

       

      
        void GerenciadorEstado::addEstado(const Estado::stateID ID){
            Estado::Estado* estado = nullptr;
            //estado = dynamic_cast<Estado::Estado*>(new Estado::EstadoMenu(ID));
            if(
                ID == Estado::stateID::menuPrincipal//||
            ){
               estado = static_cast<Estado::Estado*>(new Estado::EstadoMenu(ID));
            } else if(
                ID == Estado::stateID::jogar_lava ||
                ID == Estado::stateID::jogar_floresta//||
            ){
                estado = static_cast<Estado::Estado*>(new Estado::EstadoJogar(ID));
            }
            if(estado == nullptr){
                std::cout << "ERROR::Gerenciador::GerenciadorEstado::estado eh nullptr" << std::endl;
                exit(1);
            }
            if(!pilhaEstados.empty()){
                //desativarObservadores();
                //aqui deve puxar aquela função pra fechar a janela
            }
            //arrumar...
            pilhaEstados.push(estado);
        }

        void GerenciadorEstado::removerEstado(){
           if(pilhaEstados.top() != nullptr && !pilhaEstados.empty()){
                delete(pilhaEstados.top());
                pilhaEstados.top() = nullptr;
                pilhaEstados.pop();
            }
            if(!pilhaEstados.empty()){
                    //display off , algo assim
                Gerenciadores::Gerenciador_Grafico* pGrafico = pGrafico->getInstancia();
                pGrafico->fechaJanela();
            } 
           /*
            else {
            }
           */
        }
        /*
        
        void GerenciadorEstado::removerEstado(const int qtd){
            int i = 0;
            while(!pilhaEstados.empty() && i < qtd){
                Estado::Estado* estado = pilhaEstados.top();
                if(estado != nullptr){
                    delete(estado);
                    estado = nullptr; 
                }
                pilhaEstados.pop();
                i++;
            }
            if(!pilhaEstados.empty()){
            } else {
                GerenciadorGrafico* pGrafico = pGrafico->getGerenciadorGrafico();
                pGrafico->fecharJanela();
            }
        */
        Estado::Estado* GerenciadorEstado::getEstadoAtual() {
            if(!pilhaEstados.empty()){
                return pilhaEstados.top();
            }
            return nullptr;
        }
        /*
        */

        Estado::Estado* GerenciadorEstado::getEstado(const int qtdRemove){
            std::stack<Estado::Estado*> pilhaEstadoAux = pilhaEstados;
            int i = 0;
            while(i < qtdRemove && !pilhaEstadoAux.empty()){
                pilhaEstadoAux.pop(); 
                i++;
            }
            if(!pilhaEstadoAux.empty()){
                return pilhaEstadoAux.top();
            }
            return nullptr;
        }

        void GerenciadorEstado::executar(){
            //executa o estado que está no topo da minha pilha
            if(!pilhaEstados.empty()){
                Estado::Estado* estado = pilhaEstados.top();
                estado->executar();
                //cout<<""<<estado->ID<<endl;
                //pEstadoAtual->executar();
            }else cout<<"caiu no else viado"<<endl;
        }
        }

    //}

