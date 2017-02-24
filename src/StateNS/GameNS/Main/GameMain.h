#pragma once
#include "../../../Data.h"
#include "../GameParent.h"
#include "../GameChild.h"

//Player等のクラスは名前空間なし
class Player;
class Stage;
class System;

namespace StateNS {
namespace GameStateNS {


//ゲームの本編のクラス
class GameMain : public GameChild
{
public:
	GameMain();
	~GameMain();

	GameChild* update(GameParent*);
	void draw() const;	
	bool drawDebug();

private:
	Player *player;
	Stage* stage;
	System* system;

};




}
}

