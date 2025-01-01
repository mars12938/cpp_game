#include "stdafx.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

class VisibleGameObject
{
    public:
        VisibleGameObject();
        virtual ~VisibleGameObject();

        virtual void Load(std::string filename);
        virtual void Draw(sf::RenderWindow& window);
        virtual void SetPosition(float x, float y);

    private:
        //sf::Sprite sprite;
        std::unique_ptr<sf::Sprite>sprite;
        sf::Texture texture;
        std::string filename;
        bool isLoaded;
};

