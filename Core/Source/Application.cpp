#include "Pch.h"
#include "Application.h"

Application::Application()
	:
	clock(new sf::Clock()),
	texture(new SpriteSheet),
	canvas(new Canvas("map.tilemap"))
{
	window = new sf::RenderWindow(sf::VideoMode(resolution.x, resolution.y), title);
}

Application::~Application()
{
	//Members
	if (canvas != nullptr)
	{
		delete canvas;
	}
	delete texture;
	delete clock;
	delete window;
}

void Application::Start()
{
	texture->LoadDebugTexture();
	canvas = new Canvas("map.tilemap");
	canvas->SetupSprites(texture);
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
	canvas->Draw(window);
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
