#include "JC_Square.h"

JC_Square::JC_Square()
{
	Init();
}

JC_Square::~JC_Square()
{

}


void JC_Square::Init()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = 10;
	rect.h = 10;
	R = 0;
	G = 0;
	B = 0;
}

void JC_Square::Render(SDL_Renderer* aRenderer, int pX, int pY)
{
	rect.x = pX;
	rect.y = pY;
	SDL_SetRenderDrawColor(aRenderer, R, G, B, 255);
	SDL_RenderFillRect(aRenderer, &rect);
}

void JC_Square::MakeRed()
{
	R = 255;
	G = 0;
	B = 0;
}

void JC_Square::MakeBlue()
{
	R = 0;
	G = 0;
	B = 255;
}
