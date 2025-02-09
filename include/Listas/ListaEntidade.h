#pragma once
#include"Lista.h"
#include"Entidade.h"
#include "../Personagens/Personagem.h"

/*Em todas as entidades o executar desenha a entidade e as demais coisas que ela deve fazer. Ex: se ela é um inimigo e ele se move sozinho, 
o executar faz ele se mover (a partir de um método, como "movimenta()").

Na lista é bom ter uma função que executa tudo
*/


namespace Lista{

    class ListaEntidade
    {
    private:
            
        Lista <Entidades::Entidade> LEs;

    public:
        ListaEntidade();
        
        ~ListaEntidade();

        void incluir(Entidades::Entidade* pE);

        void excluir (Entidades::Entidade* pE);

        void percorrer();

        // void atualizar(float tempo);

        int getTamanho() const;

        Lista<Entidades::Entidade>& getLista();
    };
    
}