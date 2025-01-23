#include "../include/manager/Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista::ListaEntidade* listaPersonagem , Lista::ListaEntidade* listaObstaculo)
{

}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
}

const sf::Vector2f Gerenciador_Colisoes::gerenciaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2){
    sf::Vector2f pos1 = ent1->getPosicao();
    sf::Vector2f pos2 = ent2->getPosicao();

    sf::Vector2f tam1 = ent1->getTam();
    sf::Vector2f tam2 = ent2->getTam();
    
    sf::Vector2f distanciaEntreCentros(fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)),
        fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f)));

    sf::Vector2f somaMetadeRetangulo(tam1.x/2.0f + tam2.x/2.0f, tam1.y/2.0f + tam2.y/2.0f);

    return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRetangulo.x, distanciaEntreCentros.y - somaMetadeRetangulo.y);
}

void Gerenciador_Colisoes::executar(){
    for(int i = 0; i < listaPersonagem->getTamanho() - 1; i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
        for(int j = i + 1; j < listaPersonagem->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaPersonagem->getLista().operator[](j);
            sf::Vector2f ds = gerenciaColisao(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent1->colisao(ent2, ds);
            } //adicionei operator na listaEntidade mas esta dando erro
            //no return. Precisaria ter operator em Lista.
        }
    }

    for(int i = 0; i < listaPersonagem->getTamanho(); i++){
        Entidades::Entidade* ent1 = listaPersonagem->getLista().operator[](i);
        for(int j = 0; j < listaObstaculo->getTamanho(); j++){
            Entidades::Entidade* ent2 = listaObstaculo->getLista().operator[](j);
            sf::Vector2f ds = gerenciaColisao(ent1, ent2);
            if(ds.x < 0.0f && ds.y < 0.0f){
                ent2->colisao(ent1, ds);
            }
        }
    }


}