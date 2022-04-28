#include "Pch.h"
#include "SpriteSheet.h"


SpriteSheet::SpriteSheet()
{
    Clear();
}

SpriteSheet::~SpriteSheet()
{
    if (texture != nullptr)
        delete texture;
}

void SpriteSheet::LoadTexture()
{
    std::cout << " == LOAD TEXTURE == \n\n";
    std::cout << " Texture Label: ";
    std::getline(std::cin, name);
    std::cout << "File Path (from prgm dir): ";
    std::getline(std::cin, name);
    std::cout << "Resolution:\n  X:";
    std::cin >> resolution.x;
    std::cout << "  Y:";
    std::cin >> resolution.y;
    std::cout << "Padding:\n  X:";
    std::cin >> padding.x;
    std::cout << "  Y:";
    std::cin >> padding.y;
    std::cout << "Dimensions:\n  X:";
    std::cin >> dimensions.x;
    std::cout << "  Y:";
    std::cin >> dimensions.y;

    texture = new sf::Texture;
    if (!texture->loadFromFile(path))
    {
        std::cout << "[INFO] Could not open file at path: " << path << std::endl;
        Clear();
        return;
    }
}

void SpriteSheet::LoadDebugTexture()
{
    name = "Debug";
    path = "terrain.png";
    resolution = { 32, 32 };
    dimensions = { 16, 16 };

    texture = new sf::Texture;
    if (!texture->loadFromFile(path))
    {
        std::cout << "[INFO] Could not open file at path: " << path << std::endl;
        Clear();
        return;
    }
}

void SpriteSheet::Clear()
{
    if (texture != nullptr)
    {
        delete texture;
    }
    name = "";
    path = "";
    resolution = { 0, 0 };
    padding = { 0, 0 };
    dimensions = { 0, 0 };
}

void SpriteSheet::SetupSprite(sf::Sprite* sprite, const int id) const
{
    if (texture == nullptr)
    {
        std::cout << "[ERROR] Could not setup sprite. Texture must be loaded" << std::endl;
        return;
    }
    else if (id >= dimensions.x * dimensions.y)
    {
        std::cout << "[ERROR] Could not setup sprite. ID outside of available sprites" << std::endl;
        return;
    }

    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::Rect(
        (id % dimensions.y) * resolution.x + (id * padding.x),
        (id / dimensions.y) * resolution.y + (id * padding.y),
        resolution.x,
        resolution.y
    ));
}

sf::Texture* SpriteSheet::GetTextureRef() const
{
    return texture;
}

std::string SpriteSheet::GetName() const
{
    return name;
}

std::string SpriteSheet::GetPath() const
{
    return path;
}

sf::Vector2<int> SpriteSheet::GetResolution() const
{
    return resolution;
}

sf::Vector2<int> SpriteSheet::GetPadding() const
{
    return padding;
}

sf::Vector2<int> SpriteSheet::GetDimensions() const
{
    return dimensions;
}

sf::Vector2<int> SpriteSheet::GetPixelDimensions() const
{
    return (texture != nullptr) ? (sf::Vector2<int>)texture->getSize() : sf::Vector2<int>{ 0, 0};
}
