#pragma once
#include "Child.h"

namespace StateNS{

class Parent;

class Title : public Child
{
public:
	Title::Title();
	Title::~Title();
	Child* update(Parent*);
	void draw() const;
	bool drawDebug();

private:
	int backImg;

};


}