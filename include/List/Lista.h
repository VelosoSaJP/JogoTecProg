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
                TE *pInfo;
            
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
                    if(p)
                        pInfo = p;
                }

                void setProx(Elemento<TE> *pE){
                    if(pE)
                        pPROX = pE;
                }

                Elemento<TE>* getPRoximo(){
                    return pPROX;
                }

                /*Elemento<TE>* getInfo(){
                    return pInfo;
                }Caso for necessário, é só descomentar*/ 

        };// Classe Elemento

                Elemento<TL>* pPrimeiro;
                Elemento<TL>* pUltimo;

            public:

                Lista(){
                    pPrimeiro = nullptr;
                    pUltimo = nullptr;
                }

                ~Lista(){
                    pPrimeiro = nullptr;
                    pUltimo = nullptr;
                }

                void incluir(TL* p){
                    if(p)
                        Lista.push(p);
                    else
                        std::cout<<"Sem p para dar push em Lista.h"<<std::endl;

                }

                void limpar();






    };

} // namespace Lista
