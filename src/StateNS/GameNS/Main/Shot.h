#pragma once
#include "../../../Data.h"
#include <vector>

class Shot;

//�S�Ă�shot��ۊǂ��Ă����ϒ��z��
static std::vector<Shot*> shot;

//�摜�t�@�C����ǂݍ���
void loadImageFile(char* fileName);

//vector�ɐV����Shot��ǉ�
void push_shot(Shot* _s);

//�e���X�V
void update_shot();

//�e��`��
void draw_shot();

//shot�����
void deleteAllShot();



//====================================
//Shot�N���X
//====================================
class Shot {

private:
	Point* p;//�����ł͍��W��1000�{���ĕۑ����Ă���
	float angle;//angle = 0�Ő����E����
	float dx;
	float dy;

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
	const Point* getPoint();
	bool isExit();
};
