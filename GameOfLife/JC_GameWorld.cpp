#include "JC_GameWorld.h"
#include <iostream>
using namespace std;

JC_GameWorld::JC_GameWorld()
{
	Init();
	GameLoop();
}

JC_GameWorld::~JC_GameWorld()
{
	OnClose();
}

void JC_GameWorld::Init()
{

}

void JC_GameWorld::GameLoop()
{
	while (done != true)
	{
		startMs = SDL_GetTicks(); //when the frame starts 

		Update();
		Render();

		endMs = SDL_GetTicks(); //when the frame calculations end 
		delayMs = frameMs - (endMs - startMs); //how long to delay 
		SDL_Delay(delayMs);
		currentFrame++;
	}
}

void JC_GameWorld::Update()
{
	while (SDL_PollEvent(&_event))
	{
		if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL)
		{
			switch (_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = true;
				break;
			case SDLK_p:
				pause = !pause;
				break;
			}
		}

		if (_event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (pause == true)
			{
				SDL_GetMouseState(&mousePosX, &mousePosY);
				aSquareContainer.OnClickChange(mousePosX, mousePosY);
			}
		}
	}
	if (pause == false)
		aSquareContainer.Update();
}

void JC_GameWorld::Render()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);

	aSquareContainer.Render(renderer);

	SDL_SetRenderDrawColor(renderer, 10, 0, 20, 255);
	SDL_RenderPresent(renderer);
}

void JC_GameWorld::OnClose()
{

}