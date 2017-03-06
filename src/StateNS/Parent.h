#pragma once
#include "Child.h"

namespace StateNS{

	class Child;

class Parent
{
public:
	Parent::Parent();
	Parent::~Parent();
	
	Child* update();
	void draw() const;
	bool drawDebug();

	void moveTo();
	
private:
	Child* mChild;
};


}