#pragma once
#include "Ente.h"//útil para as classes herdadas
#include "json.hpp"
#include "fstream"
#include "ListaEntidade.h"
#include "../Personagens/Jogador.h"
#include "../Personagens/Orc.h"
#include "../Personagens/Esqueleto.h"
#include "../Personagens/Mago.h"
#include "../manager/Gerenciador_Grafico.h"
#include "../manager/Gerenciador_Eventos.h"


// #include "Gerenciador_Colisoes.h"
namespace Fases{
    class Fase{
        protected:
            //static ? -> singleton Gerenciadores::Gerenciador_Colisoes* pGC;

            Lista::ListaEntidade* pLE;
            Gerenciadores::Gerenciador_Grafico* pGG;
            Gerenciadores::Gerenciador_Eventos* pGE;
           

        public:
            Fase();
            ~Fase();
            void gerenciarColisoes();
            void executar();
            void criarJogadores(int jog,sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarFase()=0;
            virtual void criarPlataformas(sf::Vector2f posicao, sf::Vector2f tamanho)=0;
            virtual void criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho)=0;
            virtual void criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho)=0;
            
    };
}

//criar cenário já vai ter a árvore e afins
//é necessário apenas identificar os números na matriz json dos arquivos
