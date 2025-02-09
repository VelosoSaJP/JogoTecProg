#include "../../include/Estado/Estado.h"


    namespace Estado {

        Estado::Estado(){}

        Estado::Estado(const stateID ID):
            /*Ente(ID), talvez eu nem precise chamar essa*/ 
            remover(false)
        {
            this->ID = ID;
        }

        Estado::~Estado(){
            
        }

        void Estado::desenhar(){

        }

        void Estado::setRemover(const bool remover){
            this->remover = remover;
        }

        const bool Estado::getRemover() const {
            return remover;
        }

    }

