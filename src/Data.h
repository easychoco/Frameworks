#pragma once

#include <cassert> //assert(false) で停止
#include <array> //組み込み配列よりstd::arrayのほうが安全

#include"DXLib.h"


//円周率
#define Pi 3.14159265358979f


//deleteと0ポインタ
#define SAFE_DELETE(p){\
	delete (p);\
	(p) = 0;\
}

//delete[]と0ポインタ
#define SAFE_DELETE_ARRAY(p){\
	delete[] (p);\
	(p) = 0;\
}

//穴あき配列をSAFE_DELETE
#define SAFE_DELETE_EACH(p){\
	for(auto a : dynamic_cast<p>)SAFE_DELETE(a);\
}


//整数型2次元座標 + 幅高さのクラス
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
