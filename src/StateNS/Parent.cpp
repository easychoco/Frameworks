#include "../Data.h"
#include "Parent.h"
#include "Title.h"

namespace StateNS {


Parent::Parent()
{
	this->mChild = new Title();
}

Parent::~Parent() 
{
	SAFE_DELETE(mChild);
}

Child* Parent::update() 
{
	//返り値は次のシーケンス
	Child* next = mChild->update(this);

	//シーケンス遷移
	if (next != mChild) {
		SAFE_DELETE(mChild);
		mChild = next;
	}

	next = 0;

	return next;
}

void Parent::draw() const 
{
	mChild->draw();
}

bool Parent::drawDebug() 
{
	return mChild->drawDebug();
}

void Parent::moveTo() 
{
	
}







}
