#include "../include/Personagens/Inimigo.h"
#include <cmath>

namespace Entidades{
namespace Personagens{
    Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, int ID):
        Personagem(pos,tam,ID),
        nivel_maldade(0),
        pos_inicialX(pos.x),
        tam_plataforma(80),
        direita(false)
    {
    }
    
    Inimigo:: Inimigo(){

    }
    Inimigo:: ~Inimigo(){

    }


    void Inimigo::andar(bool parede){
         float limite_mov=(tam_plataforma/2)-tamanho.x;
         
      if (direita){
            velocidade.x = pGG->getDeltaTime() *0.025;
                pSprite -> move(velocidade.x,velocidade.y );
       
        }
        else{
             velocidade.x = pGG->getDeltaTime() *0.025;
                pSprite -> move(-velocidade.x,velocidade.y );
        }
        
        if(fabs(pSprite->getPosition().x-pos_inicialX)+16>limite_mov){
                pSprite->setOrigin(pSprite->getLocalBounds().width / 2, pSprite->getOrigin().y); //suaviza a mudança de direção.Faz com que gire no próprio eixo.
                pSprite->setScale(-1*pSprite->getScale().x,pSprite->getScale().y);
                direita=!direita;
        }
           
       
    }

}
}