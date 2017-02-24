#include"Snow.h"
#include"DXLib.h"

#include<cmath>

#define Pi 3.14159265358979f

static int img;

Snow::Snow(int _init_x, int _speed, double _rate) :
fin(false),
init_x(_init_x),
speed(_speed),
rate(_rate),
time(0),
x(0),
y(0) 
{

}

Snow::~Snow() {}

void Snow::LoadFile(char* filename)
 {
	img = LoadGraph(filename);
}

void Snow::update()
{
	this->update(0, 0);
}

void Snow::update(int dx, int dy) 
{
	if(fin)return;
	time++;

	init_x += dx;
	if (init_x < 0)init_x += 640;
	x = init_x + (int)(10 * sin(time * Pi / 60));

	y += (speed + dy);
	if (y < 0)y += 480;
	init_x %= 640;
	x %= 640;

	if (y > 500)fin = true;
}

void Snow::draw() const
{
	if(fin)return;
	DrawRotaGraph(x, y, rate, time * speed * Pi / 180.0, img, true);
}
