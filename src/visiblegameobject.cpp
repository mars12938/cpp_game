#include "stdafx.h"
#include "visiblegameobject.h"

VisibleGameObject::VisibleGameObject()
{
    isLoaded = false;
}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::Load(std::string filename)
{
    if(texture.loadFromFile(filename) == false)
    {
        filename = "";
        isLoaded = false;
    }
    else
    {
        filename = filename;

        const sf::Texture image(filename);
        texture = image; 
        sprite = std::make_unique<sf::Sprite>(texture);
        //sprite(image);


        //sprite.SetImage(image);
        isLoaded = true;
    }
}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow)
{
    if(isLoaded)
    {
        renderWindow.draw(*sprite);
    }
}

void VisibleGameObject::SetPosition(float x, float y)
{
    if(isLoaded)
    {
        sprite->setPosition({x,y});
    }
}
