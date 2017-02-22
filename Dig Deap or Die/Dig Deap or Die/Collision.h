#pragma once
#include "Vec2.h"
#include "Bcolider.h"

class Collision
{
	bool hasCollided = false;

	Vec2 pos;

	Vec2 Pcolider;		//point collider	; use for particles

public:

	void isColiding(Bcolider col1, Bcolider col2);
	void isColiding(Bcolider col1, Vec2 col2);
	void isColiding(Vec2 col1, Vec2 col2);
};