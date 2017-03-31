#include "../../Data.h"
#include "GameParent.h"
#include "GameChild.h"
#include "Main/GameMain.h"
#include "../Title.h"

namespace StateNS {
namespace GameStateNS{



GameParent::GameParent()
{
	mNext = NextSeq::SEQ_NONE;
	this->mChild = new GameMain();
}

GameParent::~GameParent() 
{
	SAFE_DELETE(mChild);
}

Child* GameParent::update(Parent* parent) 
{
	Child* next = this;

	GameChild* nextChild = mChild->update(this);

	//�K�w���J��
	if (nextChild != mChild) 
	{
		SAFE_DELETE(mChild);
		mChild = nextChild;
	}
	nextChild = 0;

	//�K�w�ԑJ��
	switch (mNext)
	{
	case SEQ_TITLE: next = new Title(); break;
	}

	mNext = SEQ_NONE;

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


void GameParent::moveTo(NextSeq _mNext)
{
	mNext = _mNext;
}






}
}
