#include "../include/Personagens/Inimigo.h"
#include <cmath>

namespace Entidades{
namespace Personagens{
    Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int ID, int vida, int dano):
        Personagem(pos,tam,ID,vida),
       quantidade_dano(dano),
        pos_inicialX(pos.x),
        tam_plataforma(80),
        direita(false)
    {
    }
    
    Inimigo:: Inimigo(){

    }
    Inimigo:: ~Inimigo(){

    }

  void Inimigo::andar(bool parede) {
    float limite_mov = (tam_plataforma / 2) - pSprite->getGlobalBounds().width / 2;
    
    // Definir velocidade de deslocamento
    float deslocamento = pGG->getDeltaTime() * 0.01;
    
    if (direita) {
        velocidade.x = deslocamento;
        pSprite->move(velocidade.x, velocidade.y);
    } else {
        velocidade.x = deslocamento;
        pSprite->move(-velocidade.x, velocidade.y);
    }

        // printf("Posição X: %.1f\n", pSprite->getPosition().x);
        // printf("INICIAL X: %.1f\n", pos_inicialX);
        // printf("LIMITE X: %.1f\n", limite_mov);
    // Checagem direta dos limites em vez de usar fabs
    if (pSprite->getPosition().x >= pos_inicialX + limite_mov ||
        pSprite->getPosition().x <= pos_inicialX - limite_mov)  {

        
        // Suaviza a mudança de direção
        pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y);
        
        // Inverte a escala do sprite
        pSprite->setScale(-pSprite->getScale().x, pSprite->getScale().y);
        
        // Alterna direção
        direita = !direita;
    }
}


     void Inimigo::empuxo(){}

}
}