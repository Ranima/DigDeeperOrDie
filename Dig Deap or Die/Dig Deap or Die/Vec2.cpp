#include "Vec2.h"

Vec2 operator-(Vec2 A, Vec2 B)
{
	return Vec2{ A.x - B.x, A.y - B.y };
}

Vec2 operator/(Vec2 A, float B)
{
	return Vec2{A.x / B, A.y / B};
}
