#include "stdafx.h"
#include "splashscreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
    //sf::Image image;
    sf::Texture image("images/SplashScreen.png");
    //if(image.loadFromFile("images/SplashScreen.png") != true)
        //return;
    
    
    sf::Sprite sprite(image);

    renderWindow.draw(sprite);
    renderWindow.display();

    while(true)
    {
        while(const std::optional event = renderWindow.pollEvent())
        {
            // Window closed or escape key pressed: exit
            if (event->is<sf::Event::Closed>() ||
                event->is<sf::Event::MouseButtonPressed>()
                || event->is<sf::Event::KeyPressed>())
                return;
        }
    }
}
