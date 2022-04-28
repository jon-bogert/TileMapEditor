#include "Pch.h"
#include "Canvas.h"

//Canvas::Canvas()
//	:
//	map(nullptr)
//{
//}

Canvas::Canvas(std::string path)
	:
	map(new TileMap<int>(path))
{
	for (int i = 0; i < map->GetWidth() * map->GetHeight(); i++)
	{
		sprites.push_back(new sf::Sprite);
	}
}

Canvas::~Canvas()
{
	if (map != nullptr)
	{
		delete map;
	}
	for (sf::Sprite* sprite : sprites)
	{
		delete sprite;
	}
}

void Canvas::Draw(sf::RenderWindow* window)
{
	Tile<int>* thru = map->GetStartTile();
	Tile<int>* rowBelow = thru->down;
	sf::Sprite* currentSprite;

	for (int y = 0; y < map->GetHeight(); y++)
	{
		for (int x = 0; x < map->GetWidth(); x++)
		{
			currentSprite = sprites[y * map->GetWidth() + x];
			currentSprite->setPosition(x * 32, y * 32 ); // TODO - Change 32 for scale factor
			window->draw(*currentSprite);
			thru = thru->right;
		}
		thru = rowBelow;
		rowBelow = rowBelow->down;
	}
}

void Canvas::SetupSprites(SpriteSheet* sprtsht)
{
	Tile<int>* thru = map->GetStartTile();
	Tile<int>* rowBelow = thru->down;
	sf::Sprite* currentSprite;

	for (int y = 0; y < map->GetHeight(); y++)
	{
		for (int x = 0; x < map->GetWidth(); x++)
		{
			currentSprite = sprites[y * map->GetWidth() + x];
			sprtsht->SetupSprite(currentSprite, thru->id);
			thru = thru->right;
		}
		thru = rowBelow;
		rowBelow = rowBelow->down;
	}
}


