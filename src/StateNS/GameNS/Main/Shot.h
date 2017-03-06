#pragma once
#include "../../../Data.h"
#include <vector>

class Shot;

//全てのshotを保管しておく可変長配列
static std::vector<Shot*> shot;

//画像ファイルを読み込み
void loadImageFile(char* fileName);

//vectorに新しいShotを追加
void push_shot(Shot* _s);

//弾を更新
void update_shot();

//弾を描画
void draw_shot();

//shotを解放
void deleteAllShot();



//====================================
//Shotクラス
//====================================
class Shot {

private:
	Point* p;//内部では座標を1000倍して保存しておく
	float angle;//angle = 0で水平右向き
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
	const Point* getPoint();
	bool isExit();
};
