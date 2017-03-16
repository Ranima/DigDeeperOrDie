#pragma once

//Game is in example

struct Vec2
{
	float x, y;
};

Vec2 operator-(Vec2 A, Vec2 B);
Vec2 operator/(Vec2 A, float B);