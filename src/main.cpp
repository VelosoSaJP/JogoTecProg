#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(70.f);
    shape.setFillColor(sf::Color::Red);

    // Define a posição inicial do círculo
    shape.setPosition(350.f, 250.f);

    // Velocidade base do movimento (pixels por segundo)
    float speed = 150.f; // pixels por segundo

    // Relógio para calcular o delta time
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calcula o tempo decorrido desde o último quadro
        float deltaTime = clock.restart().asSeconds();

        // Movimento do círculo baseado nas teclas pressionadas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            shape.move(0, -speed * deltaTime); // Move para cima
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape.move(-speed * deltaTime, 0); // Move para a esquerda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape.move(0, speed * deltaTime); // Move para baixo
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(speed * deltaTime, 0); // Move para a direita
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}