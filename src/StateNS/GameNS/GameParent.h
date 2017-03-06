#pragma once
#include "../Parent.h"
#include "../Child.h"
#include "GameChild.h"

namespace StateNS{

class Parent;

namespace GameStateNS{



class GameParent : public Child
{
public:
	enum NextSeq {
		//ãŠK‘w‚Ì‚İ—ñ‹“Œ^‚É‚æ‚émoveTo‚ÅˆÚ“®
		SEQ_TITLE,

		SEQ_NONE,
	};

	GameParent::GameParent();
	GameParent::~GameParent();
	
	void moveTo(NextSeq);

	Child* update(Parent*);
	void draw() const;
	bool drawDebug();
	
private:
	GameChild* mChild;
	NextSeq mNext;
};



}
}