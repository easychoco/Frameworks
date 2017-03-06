#include "Player.h"
Player::Player()
{
}

Player::~Player() 
{
	SAFE_DELETE(p);
}

void Player::update() 
{
}

void Player::draw() const 
{
	DrawFormatString(0, 50, GetColor(255, 255, 255), "Player");
}

bool Player::drawDebug()
{
	return true;
}

const Point* Player::getPoint() const 
{
	return p;
}

