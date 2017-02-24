#include "System.h"

System::System()
{
	
}

System::~System() 
{
}

void System::update() 
{

}

void System::draw() const 
{
	DrawFormatString(0, 70, GetColor(255, 255, 255), "System");
}

bool System::drawDebug()
{
	return true;
}