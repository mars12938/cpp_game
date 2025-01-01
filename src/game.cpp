#include "stdafx.h"
#include "game.h"
#include "mainmenu.h"
#include "splashscreen.h"
//#include "playerpaddle.h"

// when game created, gameState uninit
Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
PlayerPaddle Game::player1;

void Game::Start(void)
{
    if(gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode({1024, 768}, 32), "Pang!");

    player1.Load("images/paddle.png");
    player1.SetPosition((1024/2)-45, 700);

    gameState = Game::ShowingSplash;

    while(!IsExiting())
    {
        GameLoop();
    }

    mainWindow.close();

}

bool Game::IsExiting()
{
    if(gameState == Game::Exiting)
        return true;
    else
        return false;
}

void Game::GameLoop()
{
    //sf::Event currentEvent;

    //while(mainWindow.GetEvent(currentEvent))
    while(const std::optional event = mainWindow.pollEvent())
    {
        switch(gameState)
        {
            case Game::ShowingMenu:
                {
                    ShowMenu();
                    break;
                }

            case Game::ShowingSplash:
                {
                    ShowSplashScreen();
                    break;
                }

            case Game::Playing:
                {
                    std::cout << "playing\n";

                    mainWindow.clear(sf::Color(0,0,0));
                    player1.Draw(mainWindow);
                    mainWindow.display();

                    //if(currentEvent.Type == sf::Event::Closed)
                    if(event->is<sf::Event::Closed>())
                    {
                        gameState = Game::Exiting;
                    }

                    if(event->is<sf::Event::KeyPressed>())
                    {
                        if(event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
                        {
                            ShowMenu();
                        }
                    }
                    break;
                }
        }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(mainWindow);
    gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(mainWindow);

    switch(result)
    {
        case MainMenu::Exit:
            gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            gameState = Game::Playing;
            break;
    }
}













