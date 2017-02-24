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



	//ゲームの状況を判断し，管理する AI Directorクラス
	class Director {
	public :
		Director();
		~Director();

		void update(GameMain*);//constにしようか悩む
		void draw() const;

	private:
		int exciteLevel;//興奮度
		enum PlayerSkill //プレーヤースキル
		{
			SKILL_MASTER,
			SKILL_EXPERT,
			SKILL_MIDDLE,
			SKILL_NOVICE,
			SKILL_BEGINNER,

			SKILL_NONE,
		};
	};

	Director *director;

};




}
}

