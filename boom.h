#pragma once
#include "Share.h"

class BOOM
{
public:

	void init();

	void update();

	void draw();


	void exploding();

	void collision();

	void credit();

private:

	Array<TextureRegion> boom;
	Array<TextureRegion> POX;
	Array<Vec2> boom_pos;
	Array<RectF> boom_hit;
	size_t boom_size;

	Array<double> boom_w;
	Array<double> boom_h;

	Array<double> boom_vx;
	Array<double> boom_vy;

	Array<bool> under;
	bool explosion;

	bool end;
	double a;
	double time;
};

extern BOOM boom;
