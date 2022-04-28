#include "Pch.h"
#include "Application.h"

Application::Application()
	:
	clock(new sf::Clock()),
	texture(new SpriteSheet)
{
	window = new sf::RenderWindow(sf::VideoMode(resolution.x, resolution.y), title);
}

Application::~Application()
{
	//Members
	for (sf::Sprite* sprite : sprites)
	{
		delete sprite;
	}
	delete texture;
	delete clock;
	delete window;
}

void Application::Start()
{
	texture->LoadDebugTexture();
	for (int i = 0; i < 128; i++)
	{
		sf::Sprite* newSprite = new sf::Sprite;
		texture->SetupSprite(newSprite, i);
		sprites.push_back(newSprite);
	}
}

void Application::GameLoop()
{
	while (window->isOpen())
	{
		sf::Event* windowEvent = new sf::Event;
		while (window->pollEvent(*windowEvent))
		{
			if (windowEvent->type == sf::Event::Closed)
			{
				window->close();
			}
		}
		delete windowEvent;

		deltaTime = clock->getElapsedTime().asSeconds();
		clock->restart();

		window->clear(backgroundColor);

		Update();

		window->display();
	}
}

void Application::Update()
{
	int index{};
	for (sf::Sprite* sprite : sprites)
	{
		sprite->setPosition( index * sprite->getTextureRect().width , 0);
		window->draw(*sprite);
		index++;
	}
}

sf::Vector2<int> Application::GetResolution() const
{
	return resolution;
}

sf::Vector2<float> Application::GetResolutionScale() const
{
	return sf::Vector2<float>
		(
		(float)resolution.x / (float) REF_RESOLUTION.x,
		(float)resolution.y / (float)REF_RESOLUTION.y
		);
}

float Application::DeltaTime() const
{
	return deltaTime;
}
