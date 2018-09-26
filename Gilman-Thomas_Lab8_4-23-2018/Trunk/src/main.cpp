// Author: Pierce Brooks

#include <string>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

int main()
{
    float pi = 22.0f/7.0f;
    float radiansToDegrees = 180.0f/pi;
    float deltaTime;
    bool quit;
    sf::Clock clock;
    sf::RenderWindow* window;

    sf::SoundBuffer* buffer = nullptr;
    sf::Sound* sound = nullptr;
    sf::Image* image = nullptr;
    sf::Texture* texture = nullptr;
    sf::Sprite* sprite = nullptr;
    sf::Font* font = nullptr;
    sf::Text* text = nullptr;

    buffer = new sf::SoundBuffer();
    if (!buffer->loadFromFile("test.wav"))
    {
        std::cout << "ERROR 1!" << std::endl;
        delete sound;
        delete buffer;
        delete sprite;
        delete texture;
        delete image;
        delete text;
        delete font;
        return 0;
    }

    sound = new sf::Sound();
    sound->setBuffer(*buffer);
    sound->setLoop(false);

    image = new sf::Image();
    if (!image->loadFromFile("test.png"))
    {
        std::cout << "ERROR 2!" << std::endl;
        delete sound;
        delete buffer;
        delete sprite;
        delete texture;
        delete image;
        delete text;
        delete font;
        return 0;
    }

    for (unsigned int x = 0; x != image->getSize().x; ++x)
    {
        for (unsigned int y = 0; y != image->getSize().y; ++y)
        {
            sf::Color color = image->getPixel((image->getSize().x-1)-x,(image->getSize().y-1)-y);
            image->setPixel(x,y,sf::Color(~color.r,~color.g,~color.b,color.a));
        }
    }

    texture = new sf::Texture();
    if (!texture->loadFromImage(*image))
    {
        std::cout << "ERROR 3!" << std::endl;
        delete sound;
        delete buffer;
        delete sprite;
        delete texture;
        delete image;
        delete text;
        delete font;
        return 0;
    }

    sprite = new sf::Sprite();
    sprite->setTexture(*texture);
    sprite->setOrigin(sf::Vector2f(sprite->getTexture()->getSize())*0.5f);

    font = new sf::Font();
    if (!font->loadFromFile("test.ttf"))
    {
        std::cout << "ERROR 4!" << std::endl;
        delete sound;
        delete buffer;
        delete sprite;
        delete texture;
        delete image;
        delete text;
        delete font;
        return 0;
    }

    text = new sf::Text();
    text->setFont(*font);
    text->setColor(sf::Color::White);

    window = new sf::RenderWindow();
    window->create(sf::VideoMode::getFullscreenModes().back(),"Test",sf::Style::Default);
    window->setFramerateLimit(60);
    window->setView(sf::View(sf::Vector2f(window->getSize())*0.5f,sf::Vector2f(window->getSize())));
    sprite->setPosition(window->getView().getCenter());
    quit = false;
    clock.restart();

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                quit = true;
                break;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            window->close();
            quit = true;
        }

        if (quit)
        {
            continue;
        }
        deltaTime = clock.restart().asSeconds();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sound->play();
        }
        text->setString(sf::String(std::to_string(static_cast<int>(1.0f/deltaTime))));
        sprite->rotate(deltaTime*0.125f*pi*radiansToDegrees);
        window->clear(sf::Color::Black);
        window->draw(*sprite);
        window->draw(*text);
        window->display();
    }

    delete sound;
    delete buffer;
    delete sprite;
    delete texture;
    delete image;
    delete text;
    delete font;

    delete window;
    return 0;
}
