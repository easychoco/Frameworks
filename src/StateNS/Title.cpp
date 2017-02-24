#include "DxLib.h"

#include "../Data.h"
#include "../KeyInput.h"
#include "GameNS/GameParent.h"
#include "Title.h"

namespace StateNS{


Title::Title() :
backImg(0)
{
	backImg = LoadGraph("");
}

Title::~Title() 
{

}

Child* Title::update(Parent *parent) 
{
	Child* next = this;

	if (Input_Z())next = new GameStateNS::GameParent();
	
	return next;
}

void Title::draw() const 
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Title");
}

bool Title::drawDebug() 
{
	return true;
}







}
