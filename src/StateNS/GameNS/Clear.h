#pragma once
#include "../../Data.h"
#include "GameParent.h"

#include <vector>

namespace StateNS{
namespace GameStateNS{



class Clear : public GameChild
{
private:
	int backImg;


public:
	Clear::Clear();
	Clear::~Clear();
	
	GameChild* update(GameParent*);
	void draw() const;
	bool drawDebug();
	
};




}
}