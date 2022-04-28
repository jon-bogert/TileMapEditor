#include "Pch.h"
#include "Application.h"

int main()
{
	Application* application = new Application();

	application->Start();
	application->GameLoop();

	delete application;

	return 0;
}