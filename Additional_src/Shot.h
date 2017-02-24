#pragma once
#include"../../../Data.h"

class Shot {

private:
	Point* p;//�����ł͍��W��1000�{���ĕۑ����Ă���
	float angle;
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
	const Point getPoint();
	bool isExit();
};