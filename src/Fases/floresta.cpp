#include "../include/Fases/Floresta.h"

namespace Fases
{
    Floresta::Floresta():
        Fase(), //é preciso isso aqui?
        criaArvore_alteatoria(true),
        aux_arv_floresta(rand()%2)
    {   
        criarFase();
    }
    Floresta::~Floresta()
    {
    }
    void Floresta::criarFase() {
    std::ifstream arquivo("/home/murilo/code/JogoTecProg/src/Fases/Fase1.json");

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        return;
    }

    using json = nlohmann::json;
    json matriz;

    std::stringstream buffer;
    buffer << arquivo.rdbuf();
    std::string conteudo = buffer.str();

    try {
        matriz = json::parse(conteudo);
    } catch (const json::parse_error& e) {
        std::cerr << "Erro ao analisar JSON: " << e.what() << std::endl;
        return;
    }

    int sizeTiled = matriz["tilewidth"];
    int width = matriz["width"];
    int height = matriz["height"];

    // Criar a matriz usando vector<vector<int>>
    std::vector<std::vector<int>> tilemap(height, std::vector<int>(width));

    // Preenchendo a matriz com os valores do JSON
    int indice = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tilemap[y][x] = matriz["layers"][0]["data"][indice++];
        }
    }

    // Processar a matriz
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int tileId = tilemap[y][x];

            if (tileId != 0) {
                sf::Vector2f posicao(x * sizeTiled, y * sizeTiled);
                sf::Vector2f tamanho(sizeTiled, sizeTiled);

                if (tileId == 335) {
                    criarJogadores(1, posicao, tamanho);
                } else if (tileId == 334) {
                    criarJogadores(2, posicao, tamanho);
                } else if (tileId == 331 || tileId == 332 || tileId == 149 || tileId == 333) {
                    criarInimigos(tileId, posicao, tamanho);
                } else if (tileId == 298 || tileId == 407 || tileId == 297 || tileId == 224) {
                    criarObstaculo(tileId, posicao, tamanho);
                } else if (tileId == 231) {
                    criarPlataforma(posicao, tamanho, 1);
                } else if (tileId == 75) {
                    criarPlataforma(posicao, tamanho, 0);
                }
            }
        }
    }
}



void Floresta::criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    switch(id){
        case 333:{
            int aux = rand()%2;
            if(aux){
                Entidades::Personagens::Orc* pOrc = new Entidades::Personagens::Orc(posicao, sf::Vector2f(0.1,0.1),idORC,1000,100);
                pOrc->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Orc/orc.png");
                pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pOrc));

            }
            break;
        }

        case 149:{
            int aux = rand()%2;
            if(aux){
                Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075),idESQUELETO,300,30);
                pEsq->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Esqueleto/esqueleto.png");
                pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pEsq));
            }
            break;
        }
        case 331:{
            Entidades::Personagens::Orc* pOrc = new Entidades::Personagens::Orc(posicao, sf::Vector2f(0.1,0.1),idORC,1000,100);
            pOrc->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Orc/orc.png");
            pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pOrc));

            break;
        }
        case 332:{
            Entidades::Personagens::Esqueleto* pEsq = new Entidades::Personagens::Esqueleto(posicao,sf::Vector2f(0.075,0.075),idESQUELETO,300,30);
            pEsq->setTextura("/home/murilo/code/JogoTecProg/assets/Bonecos/Esqueleto/esqueleto.png");
            pLEPersonagens->incluir(static_cast<Entidades::Entidade *>(pEsq));

            break;
        }
    }

    
}
void Floresta::criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho){
    
    if(id==224){//ESCADAS DAS ÁRVORES.

        criarPlataforma(posicao,tamanho,idOBSTACULO);
            // Entidades::Obstaculos::Arvore* pArvore = new Entidades::Obstaculos::Arvore(posicao,sf::Vector2f(1,1),idOBSTACULO);
            //  pArvore->executar();
            // pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pArvore));
    }
    
    else if(id==297){
        int aux = rand()%2;
        if (aux){
            Entidades::Obstaculos::Arvore* pArvore = new Entidades::Obstaculos::Arvore(posicao,sf::Vector2f(1,1),idOBSTACULO);     
            if(criaArvore_alteatoria){ //Só o primeiro bloco cria a imagem.
                pArvore->setTextura("/home/murilo/code/JogoTecProg/assets/Fases/Fase1/props/arvore4.png");  
                criaArvore_alteatoria=false;
            }
            pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pArvore));
        }
    }
    else if(id==407){  //PEDRA ALEATÓRIA
        int aux = rand()%2;
        if (aux){
            Entidades::Obstaculos::Pedra* pPedra = new Entidades::Obstaculos::Pedra(posicao,sf::Vector2f(1,1),idPEDRA);
            pPedra->setTextura("/home/murilo/code/JogoTecProg/assets/Fases/Fase1/props/rocks1.png");  
            pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pPedra));
            
            
        }

    }
    
    
    else if (id==298){
        Entidades::Obstaculos::Pedra* pPedra = new Entidades::Obstaculos::Pedra(posicao,sf::Vector2f(1,1),idPEDRA);
        pPedra->setTextura("/home/murilo/code/JogoTecProg/assets/transparent_16x16.png");
        pLEEstaticas->incluir(static_cast<Entidades::Entidade *>(pPedra));
        sf::Sprite* pS= pPedra->getSprite();
        sf::Vector2f pos={pS->getGlobalBounds().left,pS->getGlobalBounds().top};
        printf("%.1f e %.1f\n",pos.x,pos.y);


    }
}


string Floresta::getCaminhoMapa(){
    return ("/home/murilo/code/JogoTecProg/assets/Fases/Fase1/Fase1.png");
}
}