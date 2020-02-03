#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Keyboard input");
    sf::RectangleShape player(sf::Vector2f(100.0f , 100.0f));
    player.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch(ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if(ev.text.unicode < 128)
                {
                    printf("%c",ev.text.unicode);
                }
                break;
            }

        }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
     {
         player.move(-0.1f , 0.0f);
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
     {
         player.move(0.1f , 0.0f);
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
     {
         player.move(0.0f , -0.1f);
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
     {
         player.move(0.0f , 0.1f);
     }



        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
