#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "playerpaddle.h"


/*
 * Reasons most static: exactly one instance of object will exist
 *
 *
 *
 *
 */

class PlayerPaddle;

class Game
{
    // static methods can only access static members
    // no this pointer in static method
    // cannot set static var in class ctor
    // need to init static vars outside class

    public:
        // all objects share same start function
        static void Start();

    private:
        // all functions share same functions
        // private so cannot be accessed outside class
        static bool IsExiting();
        static void GameLoop();


        static void ShowSplashScreen();
        static void ShowMenu();

        enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

        static GameState gameState;
        static sf::RenderWindow mainWindow;
        static PlayerPaddle player1;
};

