#include "../../../KeyInput.h"
#include "Shot.h"
#include <cmath>

#include "DxLib.h"



//�摜�͑S�Ă�Shot�œ���������O���[�o���ϐ���
static int img = -1;
static unsigned int black = GetColor(0, 0, 0);


//�摜�t�@�C����ǂݍ���
void loadImageFile(char* fileName)
{
	img = LoadGraph(fileName);
	assert(img != -1 && "shot::loadImageFile �摜�ǂݍ��݃G���[");
}

//vector�ɐV����Shot��ǉ�
void push_shot(Shot* _s) {

	//�g���Ă��Ȃ��e�������Ďg�p
	short new_sub{ 0 };
	for (auto s : shot)
	{
		if (s->isExit())
		{
			s = _s;
			return;
		}
	}

	//�S�Ă̒e���g�p���Ȃ�V����push
	shot.push_back(_s);
}

//�e���X�V
void update_shot()
{
	for (auto s : shot)s->update();
}

//�e��`��
void draw_shot()
{
	for (auto s : shot)s->draw();
	DrawFormatString(100, 50, GetColor(255, 255, 255), "%d", shot.size());
}

//shot�����
void deleteAllShot()
{
	shot.clear();
	shot.shrink_to_fit();
}


//====================================
//Shot�N���X
//====================================

//�摜�g�p�o�[�W����
Shot::Shot(int _x, int _y, int _w, int _h, float _angle, float _speed) :
p(new Point(_x * 1000, _y * 1000, _w, _h)),
color(black),
angle(_angle),//angle = 0�Ő����E����
fExit(false){
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
	p->x = (int)((float)p->x + dx);
	p->y = (int)((float)p->y + dy);

	//��ʊO�ɂ��邩����
	fExit = p->x < p->w * -1000 || 640000 + p->w * 1000 < p->x ||
		p->y < p->h * -1000 || 480000 + p->h * 1000 < p->y;

}

void Shot::draw() const {

	//��ʊO�ɂ�������`��Ȃ�
	if (fExit)return;

	//�摜������Ȃ�
	if (color == black)
	{
		DrawRotaGraph(p->x / 1000, p->y / 1000, 3.0, angle, img, true);
		return;
	}
	
	//�摜���Ȃ��Ȃ�
	DrawCircle(p->x / 1000, p->y / 1000, p->w, color, true);

}

const Point* Shot::getPoint() {
	return p;
}


bool Shot::isExit() {
	return fExit;
}
