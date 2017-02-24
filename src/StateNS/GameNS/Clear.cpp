#include "Clear.h"
#include "../../KeyInput.h"

namespace StateNS {
namespace GameStateNS{


//------------------------------
//Clearクラス
//------------------------------
Clear::Clear() : 
backImg(0)
{
	backImg = LoadGraph("");
}

Clear::~Clear() 
{

}

GameChild* Clear::update(GameParent* parent) 
{	
	GameChild* next = this;

	if (Input_C()) 
	{
		//タイトルへ
		parent->moveTo();
	}

	return next;
}

void Clear::draw() const 
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Clear");
	DrawGraph(0, 0, backImg, true);

}

bool Clear::drawDebug() 
{
	return true;
}





}
}
