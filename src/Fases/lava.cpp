#include "../include/Fases/Lava.h"

namespace Fases{
Lava :: Lava():
    Fase(), //é precisso disso aqui?
    aux_arvore(rand()%2),
    pProjetil(nullptr),
    cria_textura_arv(true)
{
    pProjetil = new Entidades::Projetil();    
    criarFase();
}

Lava :: ~Lava(){
 if(pProjetil){
    delete pProjetil;
}
}

void Lava::criarFase(){
 std::ifstream arquivo("/home/murilo/code/JogoTecProg/src/Fases/Fase2.json");
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
                    
                    else if(tileId==149 || tileId==423 || tileId==424 || tileId==425){
                        //orc, esq, mago
                        criarInimigos(tileId,posicao,tamanho);
                    }
                    
                    else if(tileId==269 || tileId==207 || tileId==232 || tileId==224){ //224 = árvore e =árvore fake 269 lama que queima e 232 = lava que não queima.
                        criarObstaculo(tileId,posicao,tamanho);
                    }
                    else if (tileId==379){
                        criarPlataforma(posicao,tamanho,0);
                        //tudo que será pisado.
                    }
                

                }
            }
        }
    }


void Lava::criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    switch(id){
       case 149:{
            int aux = rand()%2;
            if (aux){    
                posicao.x-=16;            
                Entidades::Personagens::Mago* pMago = new Entidades::Personagens::Mago(posicao,sf::Vector2f(0.06,0.06),idMAGO, 3000, 300);
                if (pMago){
                    pMago->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Mago/mago.png");
                    pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pMago));
                }
                
            break;
            }
       } 
       case 423:{
            int aux = rand()%2;
            if (aux){
                
                Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075),idESQUELETO,300,30);
                if(pEsq){
                    pEsq->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Esqueleto/esqueleto.png");
                    pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pEsq));
                }
            }

            break;
        }

        case 424:{
            
            Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075),idESQUELETO,300,30);
            if(pEsq){
                pEsq->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Esqueleto/esqueleto.png");
                pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pEsq));
            }
            break;

        }
        case 425:{
                posicao.x-=16;
            Entidades::Personagens::Mago* pMago = new Entidades::Personagens::Mago(posicao,sf::Vector2f(0.06,0.06),idMAGO,3000,300);
            if (pMago){
                pMago->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Mago/mago.png");
                pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pMago));
            }
            break;
        }
    }


}
void Lava::criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho){   
        if(id == 269){
            Entidades::Obstaculos::Fogo* pFogo = new Entidades::Obstaculos::Fogo(posicao,tamanho,idFOGO);
            pFogo->setTextura("/home/murilo/code/JogoTecProg/assets/transparent_16x16.png");
            pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pFogo));
 
        }
        else if(id == 232){ //lava fake
            if(rand()%2){
                Entidades::Obstaculos::Fogo* pFogo = new Entidades::Obstaculos::Fogo(posicao,tamanho,idFOGO);
                 pFogo->setTextura("/home/murilo/code/JogoTecProg/assets/transparent_16x16.png");
                pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pFogo));   
            }
        }
         else if(id == 207){ //arvore fake
             if (aux_arvore){
                 Entidades::Obstaculos::Arvore* pArvore = new Entidades::Obstaculos::Arvore(posicao,sf::Vector2f(0.65,0.65),idOBSTACULO);     
                 if(cria_textura_arv){ //Só o primeiro bloco cria a imagem.
                    pArvore->setTextura("/home/murilo/code/JogoTecProg/assets/Fases/Fase1/props/tree01.png");  
                    pArvore->executar();
                    cria_textura_arv=false;
                }
            pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pArvore));
        }
        }
         else if(id == 224){
            Entidades::Obstaculos::Arvore* pArvore = new Entidades::Obstaculos::Arvore(posicao,sf::Vector2f(0.65,0.65),idOBSTACULO);
             pArvore->setTextura("/home/murilo/code/JogoTecProg/assets/transparent_16x16.png");  
             pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pArvore)); 
         }

        
    }


string Lava::getCaminhoMapa(){
     return ("/home/murilo/code/JogoTecProg/assets/Fases/Fase2/Fase2.png");
}

}