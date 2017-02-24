#pragma once

#include <cassert> //assert(false) �Œ�~
#include <array> //�g�ݍ��ݔz����std::array�̂ق������S

#include"DXLib.h"


//�~����
#define Pi 3.14159265358979f


//delete��0�|�C���^
#define SAFE_DELETE(p){\
	delete (p);\
	(p) = 0;\
}

//delete[]��0�|�C���^
#define SAFE_DELETE_ARRAY(p){\
	delete[] (p);\
	(p) = 0;\
}

//�������z���SAFE_DELETE
#define SAFE_DELETE_EACH(p){\
	for(auto a : dynamic_cast<p>)SAFE_DELETE(a);\
}


//�����^2�������W + �������̃N���X
class Point 
{
public:
	int x;
	int y;
	int w;
	int h;

	Point() :
		Point(0, 0, 10, 10)
	{

	}
	Point(int _x, int _y) :
		Point(_x, _y, 10, 10)
	{

	}
	Point(int _x, int _y, int _w, int _h) :
		x(_x),
		y(_y),
		w(_w),
		h(_h)
	{

	}
	
	bool isZero() const 
	{
		return *this == Point::ZERO;
	}

	Point& operator += (const Point& other) 
	{
		return *this = *this + other;
	}
	Point& operator -= (const Point& other) 
	{
		return *this = *this - other;
	}
	const Point operator + (const Point& other) 
	{
		return Point(x + other.x, y + other.y, w , h);
	}
	const Point operator - (const Point& other) 
	{
		return Point(x - other.x, y - other.y, w, h);
	}
	const Point operator * (int other) const 
	{
		return Point(x * other, y * other, w, h);
	}
	const Point operator / (int other) const 
	{
		return Point(x / other, y / other, w, h);
	}
	bool operator == (const Point& other) const 
	{
		return (x == other.x) && (y == other.y);
	}
	bool operator != (const Point& other) const 
	{
		return !(*this == other);
	}
	bool isHit(Point&) const;

	static const Point ZERO;
	static const Point LEFT;
	static const Point RIGHT;
	static const Point UP;
	static const Point DOWN;
};
