#include "../include/Fases/Floresta.h"

namespace Fases
{
    Floresta::Floresta():
        Fase() //é preciso isso aqui?
    {
        criarFase();
    }
    Floresta::~Floresta()
    {
    }
    void Floresta::criarFase(){
        std::ifstream arquivo("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/src/Fases/Fase1.json");


        using json = nlohmann::json; // alias para facilitar a compreensão da máquina
        json matriz;

std::stringstream buffer;
buffer << arquivo.rdbuf();
std::string conteudo = buffer.str();

try {
    matriz = nlohmann::json::parse(conteudo);
} catch (const nlohmann::json::parse_error& e) {
    std::cerr << "Erro ao analisar JSON: " << e.what() << std::endl;
    return;
}

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

                    if(tileId==337){
                        criarJogadores(1,posicao,tamanho);
                    }

                    else if (tileId==336){
                        criarJogadores(2,posicao,tamanho);
                    }
                    
                    else if(tileId== 334 || tileId==333){
                        criarInimigos(tileId,posicao,tamanho);
                    }
                    
                    else if(tileId==204){
                    }
                    
                    else{
                        //tudo que será pisado.
                    }
                

                }
            }
        }
    }

void Floresta::criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho){
    
}
void Floresta::criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    
    switch(id){
        case 333:{
            Entidades::Personagens::Orc* pOrc = new Entidades::Personagens::Orc(posicao, sf::Vector2f(0.1,0.1),idORC);
            pOrc->setTextura("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Bonecos/Orc/orc.png");
            pLE->incluir(static_cast<Entidades::Entidade *>(pOrc));

            break;
        }
        case 334:{
            Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075),idESQUELETO);
            pEsq->setTextura("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Bonecos/Esqueleto/esqueleto.png");
            pLE->incluir(static_cast<Entidades::Entidade *>(pEsq));

            break;
        }
    }

    
}
void Floresta::criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    
}
const char* Floresta::getCaminhoMapa(){
    return ("/home/joao/Documents/TecProg/JOGO/JogoTecProg/JogoTecProg/assets/Fases/Fase1/Fase1.png");
}
}