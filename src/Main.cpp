#include "DxLib.h"

#include "KeyInput.h"
#include "StateNS/Parent.h"
#include <cassert>


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	ClearDrawScreen();

	StateNS::Parent *parent = new StateNS::Parent();

	while (!ProcessMessage() && !Input_ESCAPE()) 
	{
		ClearDrawScreen();

		parent->update();
		parent->draw();

		//releaseでは読まれない
		assert(parent->drawDebug() && "drawDebugでエラー");

		ScreenFlip();
	}

	InitGraph();

	DxLib_End();
	return 0;
}