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
                    delete pInfo;
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
            TL* /*Lista<TL>::*/operator[](int pos);

           
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
        else{
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
void Lista<TL>::remover(TL* p) {  
    Iterator it = getInicio();
    // Iterator anterior = getFinal();
    // while (it!=getFinal() ** it != p){
        // anterior = it;
        // ++it;
    // }
//  
    // while (pNode != getFinal) {
    //    
        // if (pNode->getInfo() == p) {  // Encontrou o elemento
            // Elemento<TL>* pTemp = pNode->getProx(); // Guarda o próximo nó
// 
            // if (pNode == pPrim) {
                // pPrim = pTemp; // Se for o primeiro, ajusta o início
            // } else {
                // pAnterior->setProx(pTemp);
            // }
// 
            // if (pNode == pUlt) {
                // pUlt = pAnterior; // Se for o último, ajusta o ponteiro final
            // }
// 
            // delete pNode; // Libera a memória do elemento removido
            // tam--;
// 
            // if (tam == 0) { // Se a lista ficou vazia, zera os ponteiros
                // pPrim = nullptr;
                // pUlt = nullptr;
            // }
// 
            // return;  // Sai da função após remover
        // }
// 
        // pAnterior = pNode;
        // pNode = pNode->getProx();
    // }
}


     template <class TL>
     int Lista <TL> :: getTamanho() const{
        if(tam){
           // //printf("tam: %d\n",tam);
        }
         return tam;
     }

     template <class TL>
    void Lista<TL>::limpar() {
        Elemento<TL>* pNode = pPrim;
        Elemento<TL>* pAux;

        while (pNode) {
            pAux = pNode->getProx();
            delete pNode;
            pNode = pAux;
        }

        pPrim = nullptr;
        pUlt = nullptr;
        tam = 0; // Evita acessar tamanho incorreto depois
    }

     template<class TL>
        TL* Lista<TL>::operator[](int pos){
            if(pos >= (int)tam || pos < 0){
                  throw std::out_of_range("Erro: índice fora do intervalo da lista.");
            }
            Lista<TL>::Iterator aux = getInicio();
            for(int i = 0; i < pos; i++){
                ++aux;
            }
            return *aux;
        }
     
}