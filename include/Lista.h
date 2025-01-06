#pragma once 

#include <iostream>

namespace Lista
{
    
    template<class TL>
    class Lista{
        private:
        //Classe elemento dentro de Lista
        template<class TE>
        
        class Elemento{
            private:
            
                Elemento<TE> *pPROX;
                TE* pInfo;
            
            public:

                Elemento(){
                    pPROX = nullptr;
                    pInfo = nullptr;
                }

                ~Elemento(){
                    pPROX = nullptr;
                    pInfo = nullptr;
                }

                void incluir(TE *p){
                    pInfo = p;
                }

                void setProx(Elemento<TE> *pE){
                    pPROX = pE;
                }

                Elemento<TE>* getPRoximo(){
                    return pPROX;
                }

                TE* getInfo() const{
                  return pInfo;
                } 

        }; 
                Elemento<TL>* pPrimeiro;
                Elemento<TL>* pUltimo;

            public:

                Lista();

                ~Lista();

                void incluir(TL* p);

                void limpar();

    };

}


