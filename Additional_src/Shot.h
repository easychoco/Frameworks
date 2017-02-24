#pragma once
#include"../../../Data.h"

class Shot {

private:
	Point* p;//内部では座標を1000倍して保存しておく
	float angle;
	float dx;
	float dy;

	//画面内にあるかどうか
	//trueで画面外
	bool fExit;

	//画像もしくは弾の色
	unsigned int color;


public:
	Shot(int x, int y, int w, int h, float angle, float speed);//画像ありVer.
	Shot(int x, int y, int w, int h, unsigned int color, float angle, float speed);//画像なしVer.
	~Shot();
	void update();
	void draw() const;
	const Point getPoint();
	bool isExit();
};