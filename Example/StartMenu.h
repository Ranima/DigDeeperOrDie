#pragma once

#include "BaseState.h"
#include "sfwdraw.h"
#include "Factory.h"

class menu : public BaseState
{
	ObjectPool<Entity>::iterator currentCamera;
	Factory factory;
	unsigned int spr_font;
public:
	virtual void init()
	{
		spr_font = sfw::loadTextureMap("../res/play.jpg");

		currentCamera = factory.spawnCamera(800, 600, 1);

	}
	virtual void play()
	{
		factory.spawnstartbutton(spr_font);

	}
	virtual void step() {}
	virtual size_t next() const { return 0; } // called every frame
	virtual void draw()
	{
		auto cam = currentCamera->camera->getCameraMatrix(&currentCamera->transform);



		for each(auto &e in factory)
			if (e.transform && e.sprite)
				e.sprite->draw(&e.transform, cam);
	}
};