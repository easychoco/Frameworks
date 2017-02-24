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
system(0),
director(0)
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

	director->update(this);

	//update
	stage->update();
	player->update();
	system->update();
	
	//クリア画面
	if (Input_X())
		next = new Clear();

	return next;
}

void GameMain::draw() const
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameMain");

	director->draw();

	stage->draw();
	player->draw();
	system->draw();
}

bool GameMain::drawDebug()
{
	return stage->drawDebug() & player->drawDebug() & system->drawDebug();
}

//内部クラス
GameMain::Director::Director()
{

}

GameMain::Director::~Director()
{

}

void GameMain::Director::update(GameMain* gameMain)
{
	/*
	if(exciteLevel < 10)
	{
		gameMain->enemy->pop();
		eciteLevel++;
		if(playerSkill == SKILL_MASTER)
		{
			gameMain->enemy->pop();
			gameMain->enemy->pop();
			gameMain->enemy->pop();
		}
	}
	みたいな処理
	*/
}

void GameMain::Director::draw() const
{
	DrawFormatString(200, 0, GetColor(255, 255, 255), "Director");
}


}



}
