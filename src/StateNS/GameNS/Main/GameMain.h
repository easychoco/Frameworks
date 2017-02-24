#pragma once
#include "../../../Data.h"
#include "../GameParent.h"
#include "../GameChild.h"

//Player���̃N���X�͖��O��ԂȂ�
class Player;
class Stage;
class System;

namespace StateNS {
namespace GameStateNS {


//�Q�[���̖{�҂̃N���X
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

