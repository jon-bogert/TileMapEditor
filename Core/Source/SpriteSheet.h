#pragma once
class SpriteSheet
{
private:
	sf::Texture* texture;

	std::string name;
	std::string path;
	sf::Vector2<int> resolution;
	sf::Vector2<int> padding;
	sf::Vector2<int> dimensions;

public:
	SpriteSheet();
	~SpriteSheet();
	// TODO - Copy and Assignment;

	void LoadTexture();
	void LoadDebugTexture();
	void Clear();
	void SetupSprite(sf::Sprite* sprite, const int id) const;

	sf::Texture* GetTextureRef() const;
	std::string GetName() const;
	std::string GetPath() const;
	sf::Vector2<int> GetResolution() const;
	sf::Vector2<int> GetPadding() const;
	sf::Vector2<int> GetDimensions() const;
	sf::Vector2<int> GetPixelDimensions() const;

};

