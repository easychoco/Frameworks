#pragma once
#include "../../../Data.h"
#include <vector>



class Shot {

private:
	IntPoint* p;//�����ł͍��W��1000�{���ĕۑ����Ă���
	float angle;
	float dx;
	float dy;
	int time;

	//��ʓ��ɂ��邩�ǂ���
	//true�ŉ�ʊO
	bool fExit;

	//�摜�������͒e�̐F
	unsigned int color;


public:
	Shot(int x, int y, int w, int h, float angle, float speed);//�摜����Ver.
	Shot(int x, int y, int w, int h, unsigned int color, float angle, float speed);//�摜�Ȃ�Ver.
	~Shot();
	void update();
	void draw() const;
	const Point getPoint();
	bool isExit();
};

//�S�Ă�shot��ۊǂ��Ă����ϒ��z��
static std::vector<Shot*> shot;

vector�ɐV����Shot��ǉ�
void push_shot(Shot* s) {

	//�g���Ă��Ȃ��e�������Ďg�p
	short new_sub {0};
	for (auto _s : shot) 
	{
		if (_s[i]->isExit()) 
		{
			_s[i] = shot;
			return;
		}
	}

	//�S�Ă̒e���g�p���Ȃ�V����push
	shot.push_back(s);

}

//s�����
void deleteAllShot()
{
	shot.clear();
	shot.shrink_to_fit();
}