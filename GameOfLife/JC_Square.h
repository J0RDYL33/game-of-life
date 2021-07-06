#pragma once
#include "SDL.h"
class JC_Square
{
public:
	JC_Square();
	~JC_Square();
	SDL_Rect rect;

	void Init();
	void Render(SDL_Renderer* aRenderer, int pX, int pY);
	void MakeRed();
	void MakeBlue();
	int R, B, G;
};

