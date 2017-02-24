#pragma once
#include "../../../Data.h"
#include "../../../KeyInput.h"

class Player 
{
private:
	Point *p;

public:
	Player();
	~Player();
	void update();
	void draw() const;
	bool drawDebug();
	const Point* getPoint() const;
};

