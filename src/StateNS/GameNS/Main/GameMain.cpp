#include "GameMain.h"
#include "../../../KeyInput.h"
#include "../Clear.h"
#include "Stage.h"
#include "Player.h"
#include "System.h"


namespace StateNS{
namespace GameStateNS {


GameMain::GameMain() : 
stage(0),
player(0),
system(0)
{
	stage = new Stage();
	player = new Player();
	system = new System();
}


GameMain::~GameMain() 
{
	SAFE_DELETE(stage);
	SAFE_DELETE(player);
	SAFE_DELETE(system);
}

GameChild* GameMain::update(GameParent *parent) 
{
	GameChild *next = this;

	//update
	stage->update();
	player->update();
	system->update();
	
	//ƒNƒŠƒA‰æ–Ê
	if (Input_X())
		next = new Clear();

	return next;
}

void GameMain::draw() const
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameMain");

	stage->draw();
	player->draw();
	system->draw();
}

bool GameMain::drawDebug()
{
	return stage->drawDebug() & player->drawDebug() & system->drawDebug();
}




}
}
