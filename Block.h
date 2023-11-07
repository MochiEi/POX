#pragma once
#include<Siv3D.hpp>

class BLOCK
{
public:

	void init();

	void spawn();
	void collision();
	void movement();

	void update();

	void draw();


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
