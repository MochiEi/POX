#pragma once
#include "Share.h"

class BOOM
{
public:

	void init();

	void exploding();
	void collision();

	void update();

	void draw();

private:

	Array<TextureRegion> boom;
	Array<Vec2> boom_pos;
	Array<RectF> boom_hit;
	size_t boom_size;

	Array<double> boom_w;
	Array<double> boom_h;

	Array<double> boom_vx;
	Array<double> boom_vy;

	Array<bool> under;
	bool explosion;
};

extern BOOM boom;
