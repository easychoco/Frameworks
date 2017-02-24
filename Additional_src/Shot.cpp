#include "../../../KeyInput.h"
#include "GameMain.h"
#include "Shot.h"
#include <cmath>

#include "DxLib.h"

//graph�͑S�Ă�Shot�œ���������O���[�o���ϐ���
static int graph = NULL;

static unsigned int black = GetColor(0, 0, 0);

//�摜�g�p�o�[�W����
Shot::Shot(int _x, int _y, int _w, int _h, float _angle, float _speed) :
	p(new Point(_x * 1000, _y * 1000, _w, _h)),
	color(black),
	angle(_angle - Pi / 2.0f),//�p90�x����ɂ���
	fExit(false) {

	if (!graph)graph = LoadGraph("Data/bullet.png");

	this->dx = _speed * 1000 * cos(angle);
	this->dy = _speed * 1000 * sin(angle);
}

//�摜���g�p�o�[�W����
Shot::Shot(int _x, int _y, int _w, int _h, unsigned int _color, float _angle, float _speed) : 
	p(new Point(_x * 1000, _y * 1000, _w, _h)),
	color(_color),
	angle(_angle - Pi / 2.0f),
	fExit(false){

	this->dx = _speed * 1000 * cos(angle);
	this->dy = _speed * 1000 * sin(angle);
}

Shot::~Shot() {
	SAFE_DELETE(p);
}

void Shot::update() {

	//��ʊO�ɂ�������return
	if (fExit)return;

	//�ړ�
	p->x = (float)p->x + dx;
	p->y = (float)p->y + dy;


	//��ʊO�ɂ��邩����
	fExit = p->x < p->w * -1000 || 640000 + p->w * 1000 < p->x ||
		p->y < p->h * -1000 || 480000 + p->h * 1000 < p->y;

}

void Shot::draw() const {

	//��ʊO�ɂ�������`��Ȃ�
	if (fExit)return;

	if(color == black)//�摜������Ȃ�
		DrawRotaGraph(p->x / 1000, p->y / 1000, 1.0, angle, graph, true);
	
	else//�摜���Ȃ��Ȃ�
		DrawCircle(p->x / 1000, p->y / 1000, p->w, color, true);

}

const Point Shot::getPoint() {
	return Point(p->x / 1000, p->y / 1000, p->w, p->h);
}


bool Shot::isExit() {
	return fExit;
}
