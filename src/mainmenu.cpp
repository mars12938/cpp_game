#include "stdafx.h"
#include "mainmenu.h"


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
    //Load menu image from file
    //sf::Image image;
    //image.loadFromFile("images/mainmenu.png");
    const sf::Texture image("images/mainmenu.png");
    sf::Sprite sprite(image);

    // Setup clickable regions
    //
    // Play menu item coordinates
    MenuItem playButton;
    /*
    playButton.rect.Top = 145;
    playButton.rect.Bottom = 380;
    playButton.rect.Left = 0;
    playButton.rect.Right = 1023;
    */
    sf::Vector2i position(0, 145);
    sf::Vector2i size(1023, 235);
    playButton.rect.position = position;
    playButton.rect.size = size;
    playButton.action = Play;


    // Exit menu item coordinates
    MenuItem exitButton;
    //
    /*
    exitButton.rect.Left = 0;
    exitButton.rect.Right = 1023;
    exitButton.rect.Top = 383;
    exitButton.rect.Bottom = 560;
    */
    sf::Vector2i position_e(0, 383);
    sf::Vector2i size_e(1023, 177);
    exitButton.rect.position = position_e;
    exitButton.rect.size = size_e;
    exitButton.action = Exit;


    menuItems.push_back(playButton);
    menuItems.push_back(exitButton);

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);
}


MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for (it = menuItems.begin(); it != menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        /*
        if(menuItemRect.Bottom > y
                && menuItemRect.Top < y
                && menuItemRect.Left < x
                && menuItemRect.Right > x)
        */
        
        if(menuItemRect.contains({x, y}))
        {
            std::cout<< "YESSSS";
            std::cout << (*it).action;
            return (*it).action;
        }

    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    while(true)
    {
        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::MouseButtonPressed>())
            {
                const auto* mouse_clicked = event->getIf<sf::Event::MouseButtonPressed>();


                return HandleClick(mouse_clicked->position.x, mouse_clicked->position.y);
            }
            if(event->is<sf::Event::Closed>())
            {
                return Exit;
            }
        }
    }
}

















