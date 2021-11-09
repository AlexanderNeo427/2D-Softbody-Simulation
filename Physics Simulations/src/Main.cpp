#define OLC_PGE_APPLICATION

#include "Application.h"

int main()
{
	Application* app = new Application();

	if (app->Construct(800, 600, 1, 1))
		app->Start();

	delete app;
	app = nullptr;

	return 0;
}