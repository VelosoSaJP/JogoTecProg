#include "../include/Fases/Lava.h"

namespace Fases{
Lava :: Lava():
    Fase() //é precisso disso aqui?
{
    // pGG->carregarMapaa("/home/murilo/code/JogoTecProg/assets/Fases/Fase2/Fase2.png");
    criarFase();
}

Lava :: ~Lava(){

}

void Lava::criarFase(){
 std::ifstream arquivo("Fase2.json");
        using json = nlohmann::json; // alias para facilitar a compreensão da máquina
        json matriz;

        arquivo >> matriz;
        int sizeTiled = matriz["tilewidth"];
        int width = matriz["width"];
        int height = matriz["height"];

        int indice = 0;

        // loop de entidades com tamanho fixo (sizeTiled x sizeTiled)
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int tileId = matriz["layers"][0]["data"][indice++];

                if (tileId != 0){
                    sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                    sf::Vector2f tamanho(sizeTiled, sizeTiled);

                    if(tileId==427){
                        criarJogadores(1,posicao,tamanho);
                    }

                    else if (tileId==426){
                        criarJogadores(2,posicao,tamanho);
                    }
                    
                    else if(tileId==423 || tileId==424 || tileId==425){
                        //orc, esq, mago
                        criarInimigos(tileId,posicao,tamanho);
                    }
                    
                    else if(tileId==269){
                        lava=true;
                    }
                    else if(tileId==362){
                        //escada
                    }
                    
                    else{
                        //tudo que será pisado.
                    }
                

                }
            }
        }
    }



void Lava::criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho){

}
void Lava::criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    switch(id){
        case 423:{
            Entidades::Personagens::Orc* pOrc = new Entidades::Personagens::Orc(posicao, sf::Vector2f(0.1,0.1));
            pOrc->setTextura("../../assets/Bonecos/Orc/orc.png");
            pLE->incluir(static_cast<Entidades::Entidade *>(pOrc));

            break;
        }
        case 424:{
            Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075));
            pEsq->setTextura("../../assets/Bonecos/Esqueleto/esqueleto.png");
            pLE->incluir(static_cast<Entidades::Entidade *>(pEsq));
            
            break;

        }
        case 425:{
            Entidades::Personagens::Mago* pMago = new Entidades::Personagens::Mago(posicao,sf::Vector2f(0.06,0.06));
            pMago->setTextura("../../assets/Bonecos/Mago/mago.png");
            pLE->incluir(static_cast<Entidades::Entidade *>(pMago));

            break;
        }
    }


}
void Lava::criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho){

}
const char* Lava::getCaminhoMapa(){
    return ("../../assets/Fases/Fase2/Fase2.png");
}

}