#pragma once
#include "Pch.h"
#include "SpriteSheet.h"

class Application
{
private:
	//Constants
	const sf::Vector2<int> REF_RESOLUTION = sf::Vector2<int>(1920, 1080);

	//References

	//Members
	sf::RenderWindow* window;
	sf::Vector2<int> resolution = sf::Vector2<int>(1920, 1080);
	std::string title = "Application Title";
	sf::Color backgroundColor = sf::Color::Black;

	sf::Clock* clock;
	float deltaTime{};

	SpriteSheet* texture;
	std::vector<sf::Sprite*> sprites;

public:
	Application();
	~Application();
	Application(Application()) = delete;
	Application operator=(Application()) = delete;

	void Start();
	void GameLoop();
	void Update();

	sf::Vector2<int> GetResolution() const;
	sf::Vector2<float> GetResolutionScale() const;
	float DeltaTime() const;


};

