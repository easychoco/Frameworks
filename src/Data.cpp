#include "DxLib.h"

#include "Data.h"


const Point Point::ZERO(0, 0);
const Point Point::LEFT(-1, 0);
const Point Point::RIGHT(1, 0);
const Point Point::UP(0, -1);
const Point Point::DOWN(0, 1);

//Point“¯Žm‚Ì“–‚½‚è”»’è
bool Point::isHit(Point &other) const
{
	return
		this->x - this->w / 2 <= other.x + other.w / 2 &&
		this->x + this->w / 2 >= other.x - other.w / 2 &&
		this->y - this->h / 2 <= other.y + other.h / 2 &&
		this->y + this->h / 2 >= other.y - other.h / 2;

}