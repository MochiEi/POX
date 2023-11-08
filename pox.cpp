#include <Siv3D.hpp>
#include "Share.h"
#include "pox.h"
#include "Block.h"
#include "boom.h"
#include "Map.h"

void POX::init()
{
	pox_num = 1;

	Texture Poxwalk(U"example/pox/poxwalk.png", TextureDesc::Mipped);
	Texture Poxwalk_mirror(U"example/pox/poxwalk_mirror.png", TextureDesc::Mipped);
	Texture Poxjamp(U"example/pox/poxjamp.png", TextureDesc::Mipped);
	Texture Poxjamp_mirror(U"example/pox/poxjamp_mirror.png", TextureDesc::Mipped);
	Texture Poxturn(U"example/pox/poxturn.png", TextureDesc::Mipped);

	for (int i = 0; i < 5; i++)
	{
		poxwalk << Poxwalk(40 * i, 0, 40, 65);
		poxwalk_mirror << Poxwalk_mirror(40 * i, 0, 40, 65);
		poxjamp << Poxjamp(40 * i, 0, 40, 65);
		poxjamp_mirror << Poxjamp_mirror(40 * i, 0, 40, 65);
		poxturn << Poxturn(40 * i, 0, 40, 65);
	}
}

void POX::jump()
{
	//Print << fly_vy;

	fly_vy += 400 * share.delta;

	if (fly_vy >= 200) {
		fly_vy = 200;
	}

	if (!under) {
		pox_pos.y += fly_vy * share.delta;
		if (top) {
			fly_vy = 200;
		}
	}

	if (!fly)
	{
		if (LookR)
			pox_num = 3;
		if (LookL)
			pox_num = 4;
	}

	if (fly)
	{
		if(!top)
		{
			if (KeySpace.down())
			{
				pox_move = 3;
				fly = false;
				fly_vy = -200;
				pox_pos.y -= 10;
			}
		}
	}

	if (!under)
	{
		fly = false;

		if (!fly)
		{
			pox_move += 15 * share.delta;
			if (pox_move >= 5)
			{
				pox_move = 4;
			}
		}
	}

	if (under)
	{
		if (!fly)
		{
			pox_move -= 15 * share.delta;
			if (pox_move <= -1)
			{
				fly = true;

				if (LookR) {
					pox_move = 0;
					pox_num = 1;

					if (KeyA.pressed()) {
						pox_move = 4;
						pox_num = 5;
					}
				}
				if (LookL) {
					pox_move = 4;
					pox_num = 2;

					if (KeyD.pressed()) {
						pox_move = 0;
						pox_num = 5;
					}
				}
			}
		}
	}
}

void POX::walk()
{
	if (fly)
	{
		if (LookR)
		{
			if (KeyD.pressed()) {
				pox_move += 15 * share.delta;
			}

			if (pox_move >= 5) {
				pox_move = 0;
			}
		}

		if (LookL)
		{
			if (KeyA.pressed()) {
				pox_move -= 15 * share.delta;
			}

			if (pox_move <= -1) {
				pox_move = 4;
			}
		}

		if (!LookR)
		{
			if (KeyD.down()) {
				pox_move = 0;
				pox_num = 5;
			}

			if (pox_num == 5)
			{
				pox_move += 20 * share.delta;

				if (pox_move >= 5) {
					pox_move = 0;
					pox_num = 1;
					LookR = true;
					LookL = false;
				}
			}
		}

		if (!LookL)
		{
			if (KeyA.down()) {
				pox_move = 4;
				pox_num = 5;
			}

			if (pox_num == 5)
			{
				pox_move -= 20 * share.delta;

				if (pox_move <= -1) {
					pox_move = 4;
					pox_num = 2;
					LookR = false;
					LookL = true;
				}
			}
		}
	}

	if (!right)
	{
		if (fly || !under)
		{
			if (pox_num != 5)
			{
				if (KeyD.pressed())
				{
					pox_pos = move(pox_pos);
				}
			}
		}
	}
	if (!left)
	{
		if (fly || !under)
		{
			if (pox_num != 5)
			{
				if (KeyA.pressed())
				{
					pox_pos = move(pox_pos);
				}
			}
		}
	}
}

void POX::collision()
{
	top = false;
	under = false;
	right = false;
	left = false;

	for (int i = 0; i < map.wall_size; i++)
	{
		if (pox_hit.intersects(map.wall[i]))
		{
			if (map.wall_h[i] - 5 <= pox_hit.y && pox_hit.y <= map.wall_h[i]) {
				top = true;
				pox_pos.y = map.wall_h[i];
			}
			if(fly_vy >= 0)
			{
				if (map.wall[i].y <= pox_h && pox_h <= map.wall[i].y + 5) {
					under = true;
					pox_pos.y = map.wall[i].y - pox_hit.h + 1;
				}
			}
			if (map.wall[i].y + 3 <= pox_h && map.wall[i].x <= pox_w && pox_w <= map.wall[i].x + 5) {
				right = true;
				pox_pos.x = map.wall[i].x - pox_hit.w;
			}
			if (map.wall[i].y + 3 <= pox_h && map.wall_w[i] - 5 <= pox_hit.x && pox_hit.x <= map.wall_w[i]) {
				left = true;
				pox_pos.x = map.wall_w[i];
			}
		}
	}

	for (int i = 0; i < block.block_size; i++)
	{
		if (pox_hit.intersects(block.block_hit[i]))
		{
			if (block.block_h[i] - 5 <= pox_hit.y && pox_hit.y <= block.block_h[i]) {
				top = true;
				pox_pos.y = block.block_h[i] - 1;
			}
			if (fly_vy >= 0)
			{
				if (block.block_hit[i].y <= pox_h && pox_h <= block.block_hit[i].y + 5) {
					under = true;
					pox_pos.y = block.block_hit[i].y - pox_hit.h + 1;
				}
			}
			if (block.block_hit[i].y + 3 <= pox_h && block.fixed_right[i])
				right = true;
			if (block.block_hit[i].y + 3 <= pox_h && block.fixed_left[i])
				left = true;
				
		}
	}

	//Print << top;
	//Print << under;
	//Print << right;
	//Print << left;
}

void POX::upate()
{
		collision();
		walk();
		jump();

		pox_hit = RectF(pox_pos, 40, 64);
		pox_w = pox_hit.x + pox_hit.w;
		pox_h = pox_hit.y + pox_hit.h;

	if (Key4.down())
	{
		pox_num = 0;
	}
}

void POX::draw()
{

	//pox_hit.draw(ColorF(0.3));

	if (pox_num == 1) {
		poxwalk[(int)pox_move].draw(pox_pos);
	}
	if (pox_num == 2) {
		poxwalk_mirror[(int)pox_move].draw(pox_pos);
	}
	if (pox_num == 3) {
		poxjamp[(int)pox_move].draw(pox_pos);
	}
	if (pox_num == 4) {
		poxjamp_mirror[(int)pox_move].draw(pox_pos);
	}
	if (pox_num == 5) {
		poxturn[(int)pox_move].draw(pox_pos);
	}

	//Print << pox_num;
	//Print << pox_move;
	//Print << LookR;
	//Print << LookL;
}
