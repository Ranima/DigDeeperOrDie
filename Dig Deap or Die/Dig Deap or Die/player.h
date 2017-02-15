#pragma once
#include "Transform.h"
#include "RigidBody.h"

class player
{
	Transform transform;
	RigidBody Rbody;

public:

	void init();
	void update();
	void debugdraw();
	void draw();
};