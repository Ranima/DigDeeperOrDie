#pragma once
#include "BaseState.h"
#include "sfwdraw.h"
#include "Factory.h"

class gameOver : public BaseState
{
	ObjectPool<Entity>::iterator currentCamera;
	Factory factory;
	unsigned int spr_font;

	GameState::Gamestates * currentState;
public:

	gameOver(GameState::Gamestates * stateManager)
	{
		currentState = stateManager;
	}

	virtual void init()
	{
		spr_font = sfw::loadTextureMap("../res/font.png", 32, 4);

		currentCamera = factory.spawnCamera(800, 600, 1);

	}
	virtual void play() 
	{
		factory.spawnGameOver(spr_font);
	}

	virtual void step() 
	{
		if (sfw::getMouseButton(0))
		{
			*currentState = GameState::Gamestates::Menu1;
		}
	}
	virtual size_t next() const { return 0;} // called every frame
	virtual void draw() 
	{
		auto cam = currentCamera->camera->getCameraMatrix(&currentCamera->transform);



		for each(auto &e in factory)
			if (e.transform && e.text)
				e.text->draw(&e.transform, cam);
	}
};