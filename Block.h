#pragma once
#include "Share.h"

class BLOCK
{
public:

	void init();

	void update();

	void draw();


	void spawn();

	void collision();

	void movement();


	Array<TextureRegion> block;
	Array<Vec2> block_pos;
	Array<RectF> block_hit;
	size_t block_size;

	Array<double> block_w;
	Array<double> block_h;

	Array<bool> fixed_under;
	Array<bool> fixed_right;
	Array<bool> fixed_left;

private:

	Array<bool> touch_right;
	Array<bool> touch_left;

	Array<bool> touch_box;
};

extern BLOCK block;
