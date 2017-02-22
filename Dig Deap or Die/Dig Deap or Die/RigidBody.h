#pragma once
#include "Collision.h"
#include "Vec2.h"

class RigidBody
{
	Collision collision;


public:

	bool isColliding();
};