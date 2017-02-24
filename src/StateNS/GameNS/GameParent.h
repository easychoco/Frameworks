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
	GameParent::GameParent();
	GameParent::~GameParent();
	
	void moveTo();

	Child* update(Parent*);
	void draw() const;
	bool drawDebug();
	
private:
	GameChild* mChild;
	bool fTitle;
};



}
}