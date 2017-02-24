#include "../../../KeyInput.h"
#include "GameMain.h"
#include "Shot.h"
#include <cmath>

#include "DxLib.h"

//graphは全てのShotで同じだからグローバル変数で
static int graph = NULL;

static unsigned int black = GetColor(0, 0, 0);

//画像使用バージョン
Shot::Shot(int _x, int _y, int _w, int _h, float _angle, float _speed) :
	p(new Point(_x * 1000, _y * 1000, _w, _h)),
	color(black),
	angle(_angle - Pi / 2.0f),//仰角90度を基準にする
	fExit(false) {

	if (!graph)graph = LoadGraph("Data/bullet.png");

	this->dx = _speed * 1000 * cos(angle);
	this->dy = _speed * 1000 * sin(angle);
}

//画像未使用バージョン
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

	//画面外にあったらreturn
	if (fExit)return;

	//移動
	p->x = (float)p->x + dx;
	p->y = (float)p->y + dy;


	//画面外にあるか判定
	fExit = p->x < p->w * -1000 || 640000 + p->w * 1000 < p->x ||
		p->y < p->h * -1000 || 480000 + p->h * 1000 < p->y;

}

void Shot::draw() const {

	//画面外にあったら描画なし
	if (fExit)return;

	if(color == black)//画像があるなら
		DrawRotaGraph(p->x / 1000, p->y / 1000, 1.0, angle, graph, true);
	
	else//画像がないなら
		DrawCircle(p->x / 1000, p->y / 1000, p->w, color, true);

}

const Point Shot::getPoint() {
	return Point(p->x / 1000, p->y / 1000, p->w, p->h);
}


bool Shot::isExit() {
	return fExit;
}
