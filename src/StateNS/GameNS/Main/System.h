#pragma once
#include"../../../Data.h"
#include "../../../KeyInput.h"

class System 
{
private:

public:
	System();
	~System();
	void update();
	void draw() const;
	bool drawDebug();
};



