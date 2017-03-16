#pragma once

#include "BaseState.h"
#include "sfwdraw.h"
#include "Factory.h"
#include "GameState.h"

class menu : public BaseState
{
	ObjectPool<Entity>::iterator currentCamera;
	Factory factory;
	unsigned int spr_font;

	GameState::Gamestates * currentState;

public:

	menu(GameState::Gamestates * stateManager)
	{
		currentState = stateManager;
	}

	virtual void init()
	{
		spr_font = sfw::loadTextureMap("../res/play.jpg");

		currentCamera = factory.spawnCamera(800, 600, 1);
	}
	virtual void play()
	{
		factory.spawnstartbutton(spr_font);


	}
	virtual void step() 
	{
		float x = sfw::getMouseX();
		float y = sfw::getMouseY();
		//vec2 MousePos = vec2{ x,y };

		std::cout << x << " " << y << std::endl;

		if (sfw::getMouseButton(0)/* && x >= 375 && x <= 425 && y >= 275 && y <= 325*/)
		{
			//GameState::
			//*gs.Game = gs.playing;
			*currentState = GameState::Gamestates::playing;
		}
	}
	virtual size_t next() const { return 0; } // called every frame
	virtual void draw()
	{
		auto cam = currentCamera->camera->getCameraMatrix(&currentCamera->transform);



		for each(auto &e in factory)
			if (e.transform && e.sprite)
				e.sprite->draw(&e.transform, cam);
	}
};