#include "Player.h"
#include "Shot.h"

Player::Player()
{
	loadImageFile("Data/autumn_back.png");
}

Player::~Player() 
{
	deleteAllShot();
	SAFE_DELETE(p);
}

void Player::update() 
{
	if (Input_SPACE())
	{
		push_shot(new Shot(0, 240, 10, 10, 0.0f, 2.0f));
	}

	update_shot();
}

void Player::draw() const 
{
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Player");
	draw_shot();
}

bool Player::drawDebug()
{
	return true;
}

const Point* Player::getPoint() const 
{
	return p;
}

