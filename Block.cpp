#include <Siv3D.hpp>
#include "Share.h"
#include "pox.h"
#include "Block.h"
#include "Map.h"

void BLOCK::init()
{
	Texture Block = Texture{ U"example/pox/box01.png" };
	block << Block(0, 0, 40, 40);
}

void BLOCK::spawn()
{
	if (Key1.down())
	{
		block_pos << Vec2(pox.pox_pos.x, pox.pox_pos.y - 41);

		block_size = block_pos.size();

		block_hit << RectF(block_pos[block_size - 1], 40, 64);
		block_w << block_hit[block_size - 1].x + block_hit[block_size - 1].w;
		block_h << block_hit[block_size - 1].y + block_hit[block_size - 1].h;

		fixed_under << false;
		fixed_right << false;
		fixed_left << false;

		touch_right << false;
		touch_left << false;

		touch_box << false;
	}
}

void BLOCK::collision()
{
	for (int i = 0; i < block_size; i++)
	{
		fixed_under[i] = false;
		fixed_right[i] = false;
		fixed_left[i] = false;

		touch_right[i] = false;
		touch_left[i] = false;

		touch_box[i] = false;
	}

	for (int i = 0; i < block_size; i++)
	{
		for (int j = 0; j < map.wall_size; j++)
		{
			if (block_hit[i].intersects(map.wall[j]))
			{
				if (map.wall[j].y <= block_h[i] && block_h[i] <= map.wall[j].y + 5) {
					fixed_under[i] = true;
					block_pos[i].y = map.wall[j].y - block_hit[i].h + 1;
				}
				if (map.wall[j].y + 3 <= block_h[i] && map.wall[j].x <= block_w[i] && block_w[i] <= map.wall[j].x + 10) {
					fixed_right[i] = true;
					block_pos[i].x = map.wall[j].x - block_hit[i].w + 1;
				}
				if (map.wall[j].y + 3 <= block_h[i] && map.wall_w[j] - 10 <= block_hit[i].x && block_hit[i].x <= map.wall_w[j]) {
					fixed_left[i] = true;
					block_pos[i].x = map.wall_w[j] - 1;
				}
			}
		}

		if (block_hit[i].intersects(pox.pox_hit))
		{
			if (pox.pox_hit.y <= block_h[i] && block_h[i] <= pox.pox_hit.y + 5)
				fixed_under[i] = true;
			if (block_hit[i].y + 3 <= pox.pox_h && pox.pox_pos.x <= block_w[i] && block_w[i] - 5 <= pox.pox_pos.x)
				touch_right[i] = true;
			if (block_hit[i].y + 3 <= pox.pox_h && pox.pox_w <= block_hit[i].x + 5 && block_hit[i].x <= pox.pox_w)
				touch_left[i] = true;
		}

		for (int j = 0; j < block_size; j++)
		{
			if (i != j)
			{
				if (block_hit[i].intersects(block_hit[j]))
				{
					if (block_hit[j].y <= block_h[i] && block_h[i] <= block_hit[j].y + 5) {
						fixed_under[i] = true;
						block_pos[i].y = block_pos[j].y - block_hit[i].h + 1;
					}

					if (!fixed_right[i] && !fixed_left[i])
					{
						if (block_h[i] <= block_h[j] && block_hit[j].y + 3 <= block_h[i] && block_hit[j].x <= block_w[i] && block_w[i] <= block_hit[j].x + 10) {
							touch_right[i] = true;
						}
						if (block_h[i] <= block_h[j] && block_hit[j].y + 3 <= block_h[i] && block_w[j] - 10 <= block_hit[i].x && block_hit[i].x <= block_w[j]) {
							touch_left[i] = true;
						}

						if (block_h[i] <= block_h[j] && block_hit[j].y + 3 <= block_h[i])
						{
							if (fixed_right[j]) {
								fixed_right[i] = true;
								block_pos[i].x = block_pos[j].x - block_hit[i].w + 1;
							}
							if (fixed_left[j]) {
								fixed_left[i] = true;
								block_pos[i].x = block_w[j] - 1;
							}
						}
					}
				}
			}
		}
	}

	//Print << fixed_under;
	//Print << fixed_right;
	//Print << fixed_left;
	//Print << touch_right;
	//Print << touch_left;
	//Print << touch_box;
}

void BLOCK::movement()
{
	for (int i = 0; i < block_size; i++)
	{
		if (!fixed_under[i])
			block_pos[i].y += 200 * share.delta;

		if (!fixed_left[i] && !fixed_right[i]) {
			if (touch_left[i]) {
				if (KeyD.pressed()) {
					block_pos[i] = move(block_pos[i]);
				}
			}
		}
		if (!fixed_left[i] && !fixed_right[i]) {
			if (touch_right[i]) {
				if (KeyA.pressed()) {
					block_pos[i] = move(block_pos[i]);
				}

			}
		}
	}
}

void BLOCK::update()
{
	spawn();
	collision();
	movement();

	for (int i = 0; i < block_size; i++)
	{
		block_hit[i] = RectF(block_pos[i], 40, 40);
		block_w[i] = block_hit[i].x + block_hit[i].w;
		block_h[i] = block_hit[i].y + block_hit[i].h;
	}
}

void BLOCK::draw()
{
	for (int i = 0; i < block_size; i++)
	{
		block[0].draw(block_pos[i]);
		//block_hit[i].draw(ColorF(0.1));
	}
}
