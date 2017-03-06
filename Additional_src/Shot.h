#pragma once
#include "../../../Data.h"
#include <vector>



class Shot {

private:
	IntPoint* p;//内部では座標を1000倍して保存しておく
	float angle;
	float dx;
	float dy;
	int time;

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

//全てのshotを保管しておく可変長配列
static std::vector<Shot*> shot;

vectorに新しいShotを追加
void push_shot(Shot* s) {

	//使っていない弾を見つけて使用
	short new_sub {0};
	for (auto _s : shot) 
	{
		if (_s[i]->isExit()) 
		{
			_s[i] = shot;
			return;
		}
	}

	//全ての弾を使用中なら新しくpush
	shot.push_back(s);

}

//sを解放
void deleteAllShot()
{
	shot.clear();
	shot.shrink_to_fit();
}