#pragma once
#include "Ente.h"//útil para as classes herdadas
#include "json.hpp"
#include "fstream"
#include <string>
#include "../Listas/ListaEntidade.h"
#include "../Personagens/Jogador.h"
#include "../Personagens/Orc.h"
#include "../Personagens/Esqueleto.h"
#include "../Personagens/Mago.h"
#include "../Gerenciadores/Gerenciador_Grafico.h"
#include "../Gerenciadores/Gerenciador_Eventos.h"
#include "../Gerenciadores/Gerenciador_Entradas.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
//#include "../Estado/EstadoJogar.h"

#include "../Obstaculos/Plataforma.h"
#include "../Obstaculos/Pedra.h"
#include "../Obstaculos/Fogo.h"
#include "../Obstaculos/Arvore.h"
using namespace std;

namespace Estado{
    class EstadoJogar;
}
namespace Fases{
    class Fase 
    {
        protected:


            Lista::ListaEntidade* pLEPersonagens;
            Lista::ListaEntidade* pLEEstaticas;
            Gerenciadores::Gerenciador_Grafico* pGG;
            Gerenciadores::Gerenciador_Eventos* pGE;
            Gerenciadores::Gerenciador_Entradas* pGEntradas;
            Gerenciadores::Gerenciador_Colisoes* pGColisor;
            Estado::EstadoJogar* pEstadoJogar;
            Entidades::Personagens::Mago* pMago;

            

        public:
            Fase();
            ~Fase();
            void gerenciarColisoes();
            void executar();
            void criarJogadores(int jog,sf::Vector2f posicao, sf::Vector2f tamanho);
            virtual void criarFase()=0;
            virtual void criarInimigos(int id,sf::Vector2f posicao, sf::Vector2f tamanho)=0;
            virtual void criarObstaculo(int id,sf::Vector2f posicao, sf::Vector2f tamanho)=0;
            void criarPlataforma(sf::Vector2f posicao, sf::Vector2f tamanho, int id);
            virtual string getCaminhoMapa()=0;

    };
}

