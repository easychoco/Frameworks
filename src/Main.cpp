#include "DxLib.h"

#include "KeyInput.h"
#include "StateNS/Parent.h"
#include <cassert>

static StateNS::Parent *parent = new StateNS::Parent();

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();


	while (!ProcessMessage() && !Input_ESCAPE()) 
	{
		ClearDrawScreen();

		parent->update();
		parent->draw();
		assert(parent->drawDebug() && "drawDebug‚ÅƒGƒ‰[");

		ScreenFlip();
	}

	InitGraph();

	DxLib_End();
	return 0;
}