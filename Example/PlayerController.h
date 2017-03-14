#pragma once

#include "Base.h"

class PlayerController
{

public:
	float speed = 10, turnSpeed = 1;

	float shotTimer = 0.0f;
	bool shotRequest = false;

	void poll(base::Transform *T, base::Rigidbody *rb, float dt)
	{
		if (sfw::getKey('W'))
			rb->addForce((T->getGlobalRight() * -1) * speed);

		if (sfw::getKey('A'))
			rb->addForce((T->getGlobalUp() * -1) * speed);

		if (sfw::getKey('D'))
			rb->addForce(T->getGlobalUp() * speed);

		if (sfw::getKey('S'))
			rb->addForce(T->getGlobalRight() * speed);

		shotTimer -= dt;
		if (sfw::getKey(' ') && shotTimer < 0)
		{
			shotRequest = true;
			shotTimer = 0.86f;
		}
		else shotRequest = false;
	}


};