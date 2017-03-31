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
	//�Ԃ�l�͎��̃V�[�P���X
	Child* next = mChild->update(this);

	//�V�[�P���X�J��
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
