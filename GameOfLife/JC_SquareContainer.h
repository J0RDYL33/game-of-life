#pragma once
#include "JC_Square.h"
class JC_SquareContainer
{
public:
	JC_SquareContainer();
	~JC_SquareContainer();

	bool oldBoolArray[96][96];
	bool boolArray[96][96];
	JC_Square squareArray[96][96];
	int neighbourCount;
	void Init();
	void Render(SDL_Renderer* aRenderer);
	void Update();
	void OnClickChange(int mouseX, int mouseY);

	int randForBool = 0;
};

