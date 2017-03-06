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
		//��K�w�̂ݗ񋓌^�ɂ��moveTo�ňړ�
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