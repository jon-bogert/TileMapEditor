#pragma once
#include "Pch.h"
#include "TileMap.h"
#include "SpriteSheet.h"

using namespace exo;

class Canvas
{
private:
	//References

	TileMap<int>* map;
	std::vector<sf::Sprite*> sprites;

public:
	//Canvas();
	Canvas(std::string path);
	~Canvas();

	void Draw(sf::RenderWindow* window);
	
	void SetupSprites(SpriteSheet* sprtsht);
};

