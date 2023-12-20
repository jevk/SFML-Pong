#include <SFML/Graphics.hpp>

#include <iostream>
#include "Object.h"
#include "Ball.h"
#include "Score.h"

using namespace sf;

int main()
{
    srand(time(NULL));
    bool scored = false;
    bool firstRun = true;
    RenderWindow window(sf::VideoMode(1000, 750), "Pong");

    Object player1 = Object(40, window.getSize().y / 2 - 64, 24, 128);
    player1.setFillColor(Color::White);

    Object player2 = Object(window.getSize().x - 40 - 24, window.getSize().y / 2 - 64, 24, 128);
    player2.setFillColor(Color::White);

    Ball ball = Ball(window.getSize().x / 2 - 16, window.getSize().y / 2 - 16, 32, 32, 5);
    ball.setFillColor(Color::White);
    ball.setDirection(rand() % 2 == 0 ? 1 : -1, rand() % 2 == 0 ? 1 : -1);
    ball.setPosition(window.getSize().x / 2 - 16, window.getSize().y / 2 - 16);

    Font font;
    if (!font.loadFromFile("pixel.ttf"))
		std::cout << "Error loading font" << std::endl;

    Score player1Score = Score(window.getSize().x / 2 - 100, 0, 50, 50);
    player1Score.text.setFont(font);
    player1Score.text.setFillColor(Color::White);
    player1Score.setScore(0);
    player1Score.text.setCharacterSize(50);
    player1Score.text.setString(std::to_string(player1Score.getScore()));

    Score player2Score = Score(window.getSize().x / 2 + 50, 0, 50, 50);
    player2Score.text.setFont(font);
    player2Score.text.setFillColor(Color::White);
    player2Score.setScore(0);
    player2Score.text.setCharacterSize(50);
    player2Score.text.setString(std::to_string(player2Score.getScore()));

    Text controls = Text("W/S to move player 1\nUp/Down to move player 2", font);
    controls.setFillColor(Color::White);
    // Set Position to center of screen
    controls.setPosition(window.getSize().x / 2 - controls.getGlobalBounds().width / 2, window.getSize().y / 4 - controls.getGlobalBounds().height / 2);
    controls.setFont(font);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // Close window on escape key
            if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Escape)
					window.close();

        }

        // player 1 controls with W and S
        if (Keyboard::isKeyPressed(Keyboard::W))
			player1.move(0, -5);
        if (Keyboard::isKeyPressed(Keyboard::S))
            player1.move(0, 5);

        // player 2 controls with up and down arrow keys
        if (Keyboard::isKeyPressed(Keyboard::Up))
			player2.move(0, -5);
        if (Keyboard::isKeyPressed(Keyboard::Down))
			player2.move(0, 5);

        // Lock players to screen
        if (player1.getPosition()[1] < 0)
            player1.setPosition(player1.getPosition()[0], 0);
        if (player1.getPosition()[1] + player1.getBounds()[1] > window.getSize().y)
            player1.setPosition(player1.getPosition()[0], window.getSize().y - player1.getBounds()[1]);
        if (player2.getPosition()[1] < 0)
            player2.setPosition(player2.getPosition()[0], 0);
        if (player2.getPosition()[1] + player2.getBounds()[1] > window.getSize().y)
            player2.setPosition(player2.getPosition()[0], window.getSize().y - player2.getBounds()[1]);

        // Move ball
        ball.move();

        // Bounce ball off top and bottom of screen
        if (ball.getPosition()[1] < 0) {
			ball.setPosition(ball.getPosition()[0], 0);
            ball.bounceY();
        }
        if (ball.getPosition()[1] > window.getSize().y - 32)
        {
            ball.setPosition(ball.getPosition()[0], window.getSize().y - 32);
            ball.bounceY();
        }

        // Bounce ball off players
        if (ball.shape.getGlobalBounds().intersects(player1.shape.getGlobalBounds())) {
            ball.setPosition(player1.getPosition()[0] + ball.getBounds()[0] + player1.getBounds()[0], ball.getPosition()[1]);
            ball.bounceX();
            ball.addSpeed(0.1f);
        }
        if (ball.shape.getGlobalBounds().intersects(player2.shape.getGlobalBounds())) {
			ball.setPosition(player2.getPosition()[0] - 32, ball.getPosition()[1]);
			ball.bounceX();
            ball.addSpeed(0.1f);
        }

        // Add score if ball goes off screen
        if (ball.getPosition()[0] < 0) {
			player2Score.addScore(1);
			ball.setPosition(window.getSize().x / 2 - 16, window.getSize().y / 2 - 16);
			ball.setDirection(rand() % 2 == 0 ? 1 : -1, rand() % 2 == 0 ? 1 : -1);
            scored = true;
            ball.setSpeed(5);
		}
        if (ball.getPosition()[0] > window.getSize().x - 32) {
            player1Score.addScore(1);
            ball.setPosition(window.getSize().x / 2 - 16, window.getSize().y / 2 - 16);
            ball.setDirection(rand() % 2 == 0 ? 1 : -1, rand() % 2 == 0 ? 1 : -1);
            scored = true;
            ball.setSpeed(5);
        }

        window.clear();
        window.draw(player1.shape);
        window.draw(player2.shape);
        window.draw(ball.shape);
        window.draw(player1Score.text);
        window.draw(player2Score.text);

        // Lock at 60 FPS
        sleep(milliseconds(1000 / 60));

        if (scored) {
            sleep(milliseconds(1000));
            player1.setPosition(40, window.getSize().y / 2 - 64);
            player2.setPosition(window.getSize().x - 40 - 24, window.getSize().y / 2 - 64);
            scored = false;
            window.display();
        }

        if (firstRun) {
			window.draw(controls);
            window.display();
			sleep(milliseconds(3000));
			firstRun = false;
		}

        window.display();
    }

    return 0;
}