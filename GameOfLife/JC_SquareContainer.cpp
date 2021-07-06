#include "JC_SquareContainer.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

JC_SquareContainer::JC_SquareContainer()
{
	Init();
}

JC_SquareContainer::~JC_SquareContainer()
{

}

void JC_SquareContainer::Init()
{
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 96; j++)
		{
			randForBool = rand() % 2;
			if (randForBool == 0)
			{
				boolArray[j][i] = false;
				oldBoolArray[j][i] = false;
				squareArray[j][i].MakeBlue();
			}
			else
			{
				boolArray[j][i] = true;
				oldBoolArray[j][i] = true;
				squareArray[j][i].MakeRed();
			}
		}
	}
}

void JC_SquareContainer::Render(SDL_Renderer* aRenderer)
{
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 96; j++)
		{
			squareArray[j][i].Render(aRenderer, (j * 10), (i * 10));
		}
	}
}

void JC_SquareContainer::Update()
{
	//Duplicate array to be worked with
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 96; j++)
		{
			oldBoolArray[j][i] = boolArray[j][i];
		}
	}
	//Alter array depending on neighbors
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 96; j++)
		{
			neighbourCount = 0;
			//Up
			if (i - 1 >= 0)
				if (oldBoolArray[j][i-1] == true)
					neighbourCount++;
			//Down
			if (i + 1 < 96)
				if (oldBoolArray[j][i+1] == true)
					neighbourCount++;
			//Left
			if (j - 1 >= 0)
				if (oldBoolArray[j-1][i] == true)
					neighbourCount++;
			//Right
			if (j + 1 < 96)
				if (oldBoolArray[j+1][i] == true)
					neighbourCount++;
			//Upper left
			if (i -1 >= 0 && j-1 >= 0)
				if (oldBoolArray[j - 1][i - 1] == true)
					neighbourCount++;
			//Bottom right
			if (i + 1 < 96 && j + 1 < 96)
				if (oldBoolArray[j + 1][i + 1] == true)
					neighbourCount++;
			//Upper right
			if (i - 1 >= 0 && j + 1 < 96)
				if (oldBoolArray[j + 1][i - 1] == true)
					neighbourCount++;
			//Bottom left
			if (i + 1 < 96 && j - 1 >= 0)
				if (oldBoolArray[j - 1][i + 1] == true)
					neighbourCount++;

			//Revive dead cells
			if (oldBoolArray[j][i] == 0 && neighbourCount == 3)
			{
				boolArray[j][i] = true;
				squareArray[j][i].MakeRed();
			}

			//Under-population
			else if (oldBoolArray[j][i] == 1 && neighbourCount <= 1)
			{
				boolArray[j][i] = false;
				squareArray[j][i].MakeBlue();
			}

			//Over-population
			else if (oldBoolArray[j][i] == 1 && neighbourCount > 3)
			{
				boolArray[j][i] = false;
				squareArray[j][i].MakeBlue();
			}
		}
	}
}

void JC_SquareContainer::OnClickChange(int mouseX, int mouseY)
{
	cout << "In button clicked" << endl;
	if (mouseX > -1 && mouseX < 960 && mouseY > -1 && mouseY < 960)
	{
		if (boolArray[mouseX / 10][mouseY / 10] == 0)
		{
			boolArray[mouseX / 10][mouseY / 10] = 1;
			squareArray[mouseX / 10][mouseY / 10].MakeRed();
		}
		else
		{
			boolArray[mouseX / 10][mouseY / 10] = 0;
			squareArray[mouseX / 10][mouseY / 10].MakeBlue();
		}
	}
}