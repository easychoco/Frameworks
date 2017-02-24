#pragma once
#include"../../../Data.h"

class Shot {

private:
	Point* p;//“à•”‚Å‚ÍÀ•W‚ğ1000”{‚µ‚Ä•Û‘¶‚µ‚Ä‚¨‚­
	float angle;
	float dx;
	float dy;

	//‰æ–Ê“à‚É‚ ‚é‚©‚Ç‚¤‚©
	//true‚Å‰æ–ÊŠO
	bool fExit;

	//‰æ‘œ‚à‚µ‚­‚Í’e‚ÌF
	unsigned int color;


public:
	Shot(int x, int y, int w, int h, float angle, float speed);//‰æ‘œ‚ ‚èVer.
	Shot(int x, int y, int w, int h, unsigned int color, float angle, float speed);//‰æ‘œ‚È‚µVer.
	~Shot();
	void update();
	void draw() const;
	const Point getPoint();
	bool isExit();
};