
#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    //create a bat at the bottom center of the screen
    Bat bat(1920 / 2, 1080 - 20);

    //create a ball
    Ball ball(1920 / 2, 0);

    Text hud;

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    hud.setFont(font);
    hud.setCharacterSize(76);
    hud.setFillColor(Color::White);
    hud.setPosition(20, 20);

    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                //quit the game when window is closed
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }
        
        //update delta time
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        //update the hud text 
        std::stringstream ss;
        ss << "Score: " << score << "  Lives:" << lives;
        hud.setString(ss.str());
        
        //handle ball hitting the bottom
        if (ball.getPosition().top > window.getSize().y)
        {
            //reverse the ball direction
            ball.reboundBottom();

            //remove a life
            if (lives < 1)
            {
                score = 0;
                lives = 3;
            }
        }
        //handle ball hitting the top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            score++;
        }
        //handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
        }

        window.clear();

        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
      
        window.display();
    }

    return 0;
}