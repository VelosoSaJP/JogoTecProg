#include "../../include/Estado/MaquinaEstado.h"
#include "../../include/Estado/Estado.h"


    namespace Estados{

    MaquinaEstados::MaquinaEstados(){
     
        idEstadoAtual=none;
        idUltimoEstado=none;

    }

    MaquinaEstados::~MaquinaEstados(){

        std::map<IDestado,Estado*>::iterator it;

        for(it = mapaEstados.begin();it != mapaEstados.end(); ++it){
            delete(it->second); //mesma coisa que *it qnd fazia na prova
        }
        mapaEstados.clear();
    }

    void MaquinaEstados::mudaEstadoAtual(Estados::IDestado ID){
        
        idUltimoEstado = idEstadoAtual;
        idEstadoAtual = ID;
        mapaEstados[idEstadoAtual]->resetaEstado();

    }

    void MaquinaEstados::atualizaEstadoAtual(const float dt){
        
        mapaEstados[idEstadoAtual]->update(dt);

    }

    void MaquinaEstados::renderizaEstadoAtual(){
        
        mapaEstados[idEstadoAtual]->render();
    
    }

    Estados::IDestado MaquinaEstados::getIDEstadoAtual() const{
        return idEstadoAtual;
    }

    void MaquinaEstados::insereEstadoAtual(Estados::Estado* pEstado){

        mapaEstados.insert(std::pair<IDestado, Estado*>(pEstado->getID(), pEstado));
    }

    Estados::IDestado MaquinaEstados::getUltimoID() const{
        return  idUltimoEstado;
    }        


    }

