#pragma once 

#include <iostream>

namespace Lista
{
    
    template<class TL>
    class Lista{
        private:
        //Classe elemento dentro de Lista
        template<class TE>
        
        class Elemento{ //é um atributo da classe lista.
            private:
                Elemento<TE> *pProx;
                TE* pInfo;
            
            public:

                Elemento(){
                    pProx = nullptr;
                    pInfo = nullptr;
                }

                ~Elemento(){
                    pProx = nullptr;
                    pInfo = nullptr;
                }


                void setProx(Elemento<TE> *pE){
                    pProx = pE;
                }

                void setInfo(TE* info)
                {
                    pInfo = info;
                }

                Elemento<TE>* getProx(){
                    return pProx;
                }

                TE* getInfo() const{
                  return pInfo;
                } 

                int getTamanho()const {
                    return tam;
                }

        }; 
        //demais atributos da classe lista: (elem. acabou)
                int tam;
                Elemento<TL>* pPrim;
                Elemento<TL>* pUlt;
        //ponteiros para o 1° e último elemento da lista.

        
        public://métodos da classe lista agora
        
            Lista();
            ~Lista();
            void limpar();
            void incluir(TL* p);
            void remover(TL* p);
            int getTamanho() const;
           
        class Iterator{
            private:
                    Elemento<TL>* pEl;

			public:
                
				Iterator(Elemento<TL>* pEl = nullptr)  //construtora com default para não criar uma 2º sendo esta vazia
				{
					this->pEl = pEl;
				}

				~Iterator()
				{
					pEl = nullptr;
				}
                //retorna uma referência para o próprio objeto da classe Iterator
				Iterator& operator++() //avança para o próx elemento
				{
					if (pEl != nullptr)
					{
						pEl = pEl->getProx();
					}
					return *this;
				}

				TL* operator*() //retorna o valor do elemento atual
				{
					if (pEl != nullptr)
					{
						return pEl->getInfo();
					}
					else
					{
						return nullptr;
					}
				}

				bool isNulo() const
				{
					return (pEl == nullptr);
				}

		    };
            
           Iterator getInicio() const{
                return Iterator(pPrim);
           }
         };

             /*template em c++ não possui instância concreta. Ou seja, por mais que esteja dentro 
     da classe lista, também precisará do template*/

     template <class TL>
     Lista<TL> :: Lista():
         tam(0),
         pPrim(nullptr),
         pUlt(nullptr){

        }
     
     template <class TL>
     Lista<TL> ::  ~Lista(){
         limpar();   
     }
     
     template <class TL>
     void Lista<TL>::incluir(TL* p){
        if(p!=nullptr){

        Elemento<TL>* pNode = new Elemento<TL> ();
        pNode->setInfo(p);

        if(pUlt){
            pUlt->setProx(pNode);
            pUlt = pNode;
        }
        else{//lista estava vazia.
            pPrim = pNode;
            pUlt = pNode;
        }
        tam++;
        }
        else{
            std::cout<<"Erro no ponteiro passado como parâmetro da inclusão"<<std::endl;
        }
     }

     template <class TL>
     void Lista<TL>::remover(TL* p){ //está passando o elemento que deve ser removido
        
        if(!pPrim || !p){
            return; //lista vazia ou parâmetro passado inválido
        }
        else{
            Elemento<TL>* pNode = pPrim;
            Elemento<TL>* pAnterior = nullptr;

            while(pNode!=nullptr){

                if(pNode->getInfo()!=p){
                    pAnterior=pNode;
                    pNode=pNode->getProx();
                }
                else{
                    if(pNode==pUlt){
                        pUlt=pAnterior; //tenho que atribuir pUlt aqui, pois vou apagar o node ao final
                    }
                    else if(pNode==pPrim){
                        pPrim=pNode->getProx();
                    }
                    else{
                        pAnterior->setProx(pNode->getProx());
                    }

                    delete pNode;
                    pNode=nullptr;
                    delete pAnterior;
                    pAnterior=nullptr;
                    tam--;
                }
            }
        }
     }

     template <class TL>
     int Lista <TL> :: getTamanho() const{
         return tam;
     }

     template <class TL>
     void Lista<TL>::limpar(){

        Elemento<TL>* pNode = pPrim;
        Elemento<TL>* pAux;

        while (pNode){
            pAux = pNode->getProx();
            delete pNode;
            pNode=pAux;
        }

        pPrim = nullptr;
        pUlt = nullptr;

     }
}
