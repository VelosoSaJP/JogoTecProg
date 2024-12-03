#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(25.f);
    shape.setFillColor(sf::Color::Red);

    // Define a posição inicial do círculo
    shape.setPosition(350.f, 250.f);

    // Velocidade do movimento
    float speed = 1.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Movimento do círculo baseado nas teclas pressionadas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            shape.move(0, -speed); // Move para cima
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape.move(-speed, 0); // Move para a esquerda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape.move(0, speed); // Move para baixo
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(speed, 0); // Move para a direita
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
