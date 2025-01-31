#include "../include/Gerenciadores/Gerenciador_Eventos.h"
namespace Gerenciadores{

Gerenciador_Eventos* Gerenciador_Eventos::instancia(NULL);
Gerenciador_Grafico* Gerenciador_Eventos:: pGG = Gerenciador_Grafico :: getInstancia();

Gerenciador_Eventos::Gerenciador_Eventos()
{
   
}

Gerenciador_Eventos::~Gerenciador_Eventos(){
    pGG=NULL;
}


Gerenciador_Eventos* Gerenciador_Eventos::getInstancia(){
    if (instancia == NULL){
        instancia = new Gerenciador_Eventos();
    }
        return instancia;
    
}
  
void Gerenciador_Eventos::executar(){
    sf::Event evento;

    if(pGG){
         if(pGG->janelaAberta()){

        while (pGG->eventoJanela(evento)){
        
            if(evento.type== sf :: Event:: Closed){
                pGG->fechaJanela();
            }
            if(evento.type== sf:: Event:: KeyPressed){
                 //pGE->teclaApertada(evento.key.code);
            }
            if(evento.type == sf:: Event :: KeyReleased){
                 //pGE->teclaLiberada(evento.key.code);
            }
                
        }
      }
    }
 }
}