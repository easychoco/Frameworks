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



	//�Q�[���̏󋵂𔻒f���C�Ǘ����� AI Director�N���X
	class Director {
	public :
		Director();
		~Director();

		void update(GameMain*);//const�ɂ��悤���Y��
		void draw() const;

	private:
		int exciteLevel;//�����x
		enum PlayerSkill //�v���[���[�X�L��
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

