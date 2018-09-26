//Thomas Gilman
//OOP
//Lab 6 SFML Pong
//16th April 2017
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#define SCREENWIDTH 800
#define SCREENHEIGHT 600

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    //Create Window and Load resources
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH, SCREENHEIGHT, 32), "Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::SoundBuffer ballSoundBuffer;
    if (!ballSoundBuffer.loadFromFile("resources/plop.wav"))       //BallSound effect
        return EXIT_FAILURE;
    sf::Sound ballSound(ballSoundBuffer);

    sf::Font font;
    if (!font.loadFromFile("resources/Xerox.ttf"))                  //My Free font
        return EXIT_FAILURE;

    //set variables
    const float pi = 3.14159f, paddleSpeed = 400.f;
    sf::Vector2f paddleSize(20, 75);
    float ballRadius = 10.f, ballAngle = 0.f, ballSpeed = 400.f;
    int leftScore = 0, rightScore = 0;
    sf::Clock clock, clock2;
    float pasTime;

    //create paddles
    sf::RectangleShape leftPaddle, rightPaddle, middleLine;
    leftPaddle.setSize(paddleSize - sf::Vector2f(3, 3));        //Create Left Paddle
    leftPaddle.setFillColor(sf::Color(25, 200, 100));
    leftPaddle.setOrigin(paddleSize / 2.f);
    rightPaddle.setSize(paddleSize - sf::Vector2f(3, 3));       //Create Right Paddle
    rightPaddle.setFillColor(sf::Color(200, 25, 100));
    rightPaddle.setOrigin(paddleSize / 2.f);
    middleLine.setSize(sf::Vector2f(2.f,(float)SCREENHEIGHT));  //Set Middle divider
    middleLine.setFillColor(sf::Color(255,255,255));
    middleLine.setOrigin(paddleSize / 2.f);
    middleLine.setPosition(SCREENWIDTH/2, 80);
    sf::CircleShape ball;                                       //Create Ball
    ball.setRadius(ballRadius - 3);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);

    //Set Text Messages
    sf::Text Message, leftScoreText, rightScoreText, clockText;
    Message.setFont(font);
    leftScoreText.setFont(font); rightScoreText.setFont(font);
    clockText.setFont(font);
    //Set Text Size
    Message.setCharacterSize(40);
    leftScoreText.setCharacterSize(20); rightScoreText.setCharacterSize(20);
    clockText.setCharacterSize(20);
    //Set Text Positions
    Message.setPosition(175.f, 150.f);
    leftScoreText.setPosition(10.f, 10.f); rightScoreText.setPosition(780.f, 10.f);
    clockText.setPosition(350.f, 10.f);
    //Set Text Color
    Message.setFillColor(sf::Color::White);
    leftScoreText.setFillColor(sf::Color::White); rightScoreText.setFillColor(sf::Color::White);
    clockText.setFillColor(sf::Color::White);
    //Set Text Contents
    Message.setString("Press space to start the game");
    leftScoreText.setString(std::to_string(leftScore)); rightScoreText.setString(std::to_string(rightScore));
    clockText.setString(std::to_string(clock2.getElapsedTime().asSeconds()));

    bool Playing = false, Paused = false;
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Exit program
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P))
            {
                Paused ^= 1; Playing ^= 1;  //XOR booleans
                clock.restart();            //Reset ball timing
            }
            //User wants to play
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                if (!Playing)
                {
                    Playing = true;
                    clock.restart(); clock2.restart();
                    //Set Object locations
                    leftPaddle.setPosition(10 + paddleSize.x / 2, SCREENHEIGHT / 2);
                    rightPaddle.setPosition(SCREENWIDTH - 10 - paddleSize.x / 2, SCREENHEIGHT / 2);
                    ball.setPosition(SCREENWIDTH / 2, SCREENHEIGHT / 2);
                    //adjust random angle for ball
                    do
                        ballAngle = (std::rand() % 360) * 2 * pi / 360;
                    while (std::abs(std::cos(ballAngle)) < 0.7f);
                }
            }
        }
        if (Playing)
        {
            float deltaTime = clock.restart().asSeconds(); //ball movement Variable

            //Left Player Paddle Movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
               (leftPaddle.getPosition().y - paddleSize.y / 2 > 5.f))
            {
                leftPaddle.move(0.f, -paddleSpeed * deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
               (leftPaddle.getPosition().y + paddleSize.y / 2 < SCREENHEIGHT - 5.f))
            {
                leftPaddle.move(0.f, paddleSpeed * deltaTime);
            }
            //Right Player paddle movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
               (rightPaddle.getPosition().y - paddleSize.y / 2 > 5.f))
            {
                rightPaddle.move(0.f, -paddleSpeed * deltaTime);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
               (rightPaddle.getPosition().y + paddleSize.y / 2 < SCREENHEIGHT - 5.f))
            {
                rightPaddle.move(0.f, paddleSpeed * deltaTime);
            }
            // Move the ball
            float factor = ballSpeed * deltaTime;
            ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);
            //Check Ball Collisions or Out of Bounds
            if (ball.getPosition().x - ballRadius < 0.f)
            {
                rightScore++;
                rightScoreText.setString(std::to_string(rightScore));
                clock.restart();
                ball.setPosition(SCREENWIDTH / 2, SCREENHEIGHT / 2);

                do
                    ballAngle = (std::rand() % 360) * 2 * pi / 360;
                while (std::abs(std::cos(ballAngle)) < 0.7f);
            }
            if (ball.getPosition().x + ballRadius > SCREENWIDTH)
            {
                leftScore++;
                leftScoreText.setString(std::to_string(leftScore));
                clock.restart();
                ballSpeed = 400.f;  //reset BallSpeed
                ball.setPosition(SCREENWIDTH / 2, SCREENHEIGHT / 2);

                do
                    ballAngle = (std::rand() % 360) * 2 * pi / 360;
                while (std::abs(std::cos(ballAngle)) < 0.7f);
            }
            if (ball.getPosition().y - ballRadius < 0.f)
            {
                ballSound.play();
                ballSpeed += 5.f; //increase speed of ball slowly
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);
            }
            if (ball.getPosition().y + ballRadius > SCREENHEIGHT)
            {
                ballSound.play();
                ballSpeed += 5.f; //increase speed of ball slowly
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, SCREENHEIGHT - ballRadius - 0.1f);
            }
            //Left Paddle
            if (ball.getPosition().x - ballRadius < leftPaddle.getPosition().x + paddleSize.x / 2 &&
                ball.getPosition().x - ballRadius > leftPaddle.getPosition().x &&
                ball.getPosition().y + ballRadius >= leftPaddle.getPosition().y - paddleSize.y / 2 &&
                ball.getPosition().y - ballRadius <= leftPaddle.getPosition().y + paddleSize.y / 2)
            {
                //change angle of ball when collision
                if (ball.getPosition().y > leftPaddle.getPosition().y)
                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
                else
                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;
                ballSpeed += 1.f; //increase speed of ball slowly
                ballSound.play();
                ball.setPosition(leftPaddle.getPosition().x + ballRadius + paddleSize.x / 2 + 0.1f, ball.getPosition().y);
            }
            // Right Paddle
            if (ball.getPosition().x + ballRadius > rightPaddle.getPosition().x - paddleSize.x / 2 &&
                ball.getPosition().x + ballRadius < rightPaddle.getPosition().x &&
                ball.getPosition().y + ballRadius >= rightPaddle.getPosition().y - paddleSize.y / 2 &&
                ball.getPosition().y - ballRadius <= rightPaddle.getPosition().y + paddleSize.y / 2)
            {
                //change angle of ball when collision
                if (ball.getPosition().y > rightPaddle.getPosition().y)
                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
                else
                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;
                ballSpeed += 1.f; //increase speed of ball slowly
                ballSound.play();
                ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);
            }
        }
        window.clear(sf::Color(0, 0, 0));
        clockText.setString(std::to_string(clock2.getElapsedTime().asSeconds()));
        if (Playing || Paused)                //UPDATE screen items
        {
            window.draw(middleLine);
            window.draw(leftPaddle);
            window.draw(rightPaddle);
            window.draw(ball);
            window.draw(leftScoreText);
            window.draw(rightScoreText);
            window.draw(clockText);
        }
        else
            window.draw(Message);   //Should only draw when first starting game

        window.display();
    }

    return EXIT_SUCCESS;
}
