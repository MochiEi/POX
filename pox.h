﻿#pragma once
#include <Siv3D.hpp>

class POX
{
public:

	void init();

	void jump();
	void walk();
	void collision();

	void upate();

	void draw();


	Vec2 pox_pos{ 200, 520 };
	RectF pox_hit;
	double pox_w;
	double pox_h;

private:

	Array<TextureRegion> poxwalk;
	Array<TextureRegion> poxwalk_mirror;
	Array<TextureRegion> poxjamp;
	Array<TextureRegion> poxjamp_mirror;
	Array<TextureRegion> poxturn;

	double	pox_move = 0;
	int pox_num;

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