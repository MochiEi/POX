#pragma once
#include "Share.h"

class POX
{
public:

	void init();

	void upate();

	void draw();


	void jump();

	void walk();

	void collision();


	Vec2 pox_pos{ 100, 526 };
	RectF pox_hit;
	double pox_w;
	double pox_h;
	int pox_num;

	double	pox_move = 0;

	bool obstacle;

private:

	Array<TextureRegion> poxwalk;
	Array<TextureRegion> poxwalk_mirror;
	Array<TextureRegion> poxjamp;
	Array<TextureRegion> poxjamp_mirror;
	Array<TextureRegion> poxturn;


	bool LookR = true;
	bool LookL = false;

	bool top = false;
	bool under = false;
	bool right = false;
	bool left = false;

	bool fly = true;
	double fly_vy = 5;
};

extern POX pox;
