#include "../../../KeyInput.h"
#include "Shot.h"
#include <cmath>

#include "DxLib.h"



//画像は全てのShotで同じだからグローバル変数で
static int img = -1;
static unsigned int black = GetColor(0, 0, 0);


//画像ファイルを読み込み
void loadImageFile(char* fileName)
{
	img = LoadGraph(fileName);
	assert(img != -1 && "shot::loadImageFile 画像読み込みエラー");
}

//vectorに新しいShotを追加
void push_shot(Shot* _s) {

	//使っていない弾を見つけて使用
	short new_sub{ 0 };
	for (auto s : shot)
	{
		if (s->isExit())
		{
			s = _s;
			return;
		}
	}

	//全ての弾を使用中なら新しくpush
	shot.push_back(_s);
}

//弾を更新
void update_shot()
{
	for (auto s : shot)s->update();
}

//弾を描画
void draw_shot()
{
	for (auto s : shot)s->draw();
	DrawFormatString(100, 50, GetColor(255, 255, 255), "%d", shot.size());
}

//shotを解放
void deleteAllShot()
{
	shot.clear();
	shot.shrink_to_fit();
}


//====================================
//Shotクラス
//====================================

//画像使用バージョン
Shot::Shot(int _x, int _y, int _w, int _h, float _angle, float _speed) :
p(new Point(_x * 1000, _y * 1000, _w, _h)),
color(black),
angle(_angle),//angle = 0で水平右向き
fExit(false){
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
	p->x = (int)((float)p->x + dx);
	p->y = (int)((float)p->y + dy);

	//画面外にあるか判定
	fExit = p->x < p->w * -1000 || 640000 + p->w * 1000 < p->x ||
		p->y < p->h * -1000 || 480000 + p->h * 1000 < p->y;

}

void Shot::draw() const {

	//画面外にあったら描画なし
	if (fExit)return;

	//画像があるなら
	if (color == black)
	{
		DrawRotaGraph(p->x / 1000, p->y / 1000, 3.0, angle, img, true);
		return;
	}
	
	//画像がないなら
	DrawCircle(p->x / 1000, p->y / 1000, p->w, color, true);

}

const Point* Shot::getPoint() {
	return p;
}


bool Shot::isExit() {
	return fExit;
}
