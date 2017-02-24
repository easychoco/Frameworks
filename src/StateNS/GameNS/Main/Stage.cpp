#include "Stage.h"

Stage::Stage()
{
	
}

Stage::~Stage() 
{

}

void Stage::update() 
{

}

void Stage::draw() const 
{
	DrawFormatString(0, 30, GetColor(255, 255, 255), "Stage");
}


bool Stage::drawDebug()
{
	return true;
}