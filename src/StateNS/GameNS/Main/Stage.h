#pragma once
#include"../../../Data.h"
#include "../../../KeyInput.h"

class Stage 
{
private:

public:
	Stage();
	~Stage();
	void update();
	void draw() const;
	bool drawDebug();

};



