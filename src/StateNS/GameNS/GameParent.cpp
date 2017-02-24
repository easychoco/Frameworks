#include "../../Data.h"
#include "GameParent.h"
#include "GameChild.h"
#include "Main/GameMain.h"

namespace StateNS {
namespace GameStateNS{



GameParent::GameParent() :
fTitle(false)
{
	this->mChild = new GameMain();
}

GameParent::~GameParent() 
{

}

Child* GameParent::update(Parent* parent) 
{
	Child* next = this;

	GameChild* nextChild = mChild->update(this);

	if (nextChild != mChild) 
	{
		SAFE_DELETE(mChild);
		mChild = nextChild;
	}

	nextChild = 0;
	if (fTitle)parent->moveTo();


	return next;
}

void GameParent::draw() const 
{
	mChild->draw();
}

bool GameParent::drawDebug() 
{
	return mChild->drawDebug();
}


void GameParent::moveTo() 
{
	fTitle = true;
}






}
}
