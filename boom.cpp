#include "boom.h"

void BOOM::init()
{
	Array<Texture> Boom;

	Boom << Texture(U"example/pox/ex0.png", TextureDesc::Mipped);
	Boom << Texture(U"example/pox/ex1.png", TextureDesc::Mipped);
	Boom << Texture(U"example/pox/ex2.png", TextureDesc::Mipped);
	Boom << Texture(U"example/pox/ex3.png", TextureDesc::Mipped);
	Boom << Texture(U"example/pox/ex4.png", TextureDesc::Mipped);
	Boom << Texture(U"example/pox/POX.png", TextureDesc::Mipped);

	for (int i = 0; i < 1000; i++)
	{
		boom << Boom[Random(4)];
	}

	boom_size = boom.size();

	POX << Boom[5];

	a = 0.0;
}

void BOOM::exploding()
{
	if (phrase.Break_POX)
	{
		explosion = true;

		for (int i = 0; i < boom_size; i++)
		{
			boom_pos << Vec2(pox.pox_pos.x + 20, pox.pox_pos.y + 32);
			boom_hit << RectF(boom_pos[i], 8, 8);

			boom_vx << Random(-500, 500);
			boom_vy << Random(-700, -200);

			boom_w << boom_pos[i].x + boom_hit[i].w;
			boom_h << boom_pos[i].y + boom_hit[i].h;

			under << false;
		}
	}

	if (explosion)
	{
		for (int i = 0; i < boom_size; i++)
		{

			boom_vy[i] += 400 * share.delta;

			if (boom_vy[i] >= 400) {
				boom_vy[i] = 400;
			}

			if (!under[i])
			{
				boom_pos[i].x += boom_vx[i] * share.delta;
				boom_pos[i].y += boom_vy[i] * share.delta;
			}
		}
	}
}

void BOOM::collision()
{
	for (int i = 0; i < boom_size; i++)
	{
		for (int j = 0; j < map.wall_size; j++)
		{
			if (boom_hit[i].intersects(map.wall[j]))
			{
				if (map.wall_h[j] - 5 <= boom_hit[i].y && boom_hit[i].y <= map.wall_h[j]) {
					boom_vy[i] = 400;
				}

				if (boom_vy[i] >= 0)
				{
					if (map.wall[j].y <= boom_h[i] && boom_h[i] <= map.wall[j].y + 5) {
						under[i] = true;
					}
				}

				if (map.wall[j].y + 3 <= boom_h[i] && map.wall[j].x <= boom_w[i] && boom_w[i] <= map.wall[j].x + 5) {
					boom_vx[i] = -boom_vx[i];
					boom_pos[i].x = map.wall[j].x - boom_hit[i].w;
				}

				if (map.wall[j].y + 3 <= boom_h[i] && map.wall_w[j] - 5 <= boom_hit[i].x && boom_hit[i].x <= map.wall_w[j]) {
					boom_vx[i] = -boom_vx[i];
					boom_pos[i].x = map.wall_w[j];
				}
			}
		}

		for (int j = 0; j < block.block_size; j++)
		{
			if (boom_hit[i].intersects(block.block_hit[j]))
			{
				if (block.block_h[j] - 5 <= boom_hit[i].y && boom_hit[i].y <= block.block_h[j]) {
					boom_vy[i] = 400;
				}

				if (boom_vy[i] >= 0)
				{
					if (block.block_pos[j].y <= boom_h[i] && boom_h[i] <= block.block_pos[j].y + 5) {
						under[i] = true;
					}
				}

				if (block.block_pos[j].y + 3 <= boom_h[i] && block.block_pos[j].x <= boom_w[i] && boom_w[i] <= block.block_pos[j].x + 5) {
					boom_vx[i] = -boom_vx[i];
					boom_pos[i].x = block.block_pos[j].x - boom_hit[i].w;
				}

				if (block.block_pos[j].y + 3 <= boom_h[i] && block.block_w[j] - 5 <= boom_hit[i].x && boom_hit[i].x <= block.block_w[j]) {
					boom_vx[i] = -boom_vx[i];
					boom_pos[i].x = block.block_w[j];
				}
			}
		}
	}

	end = true;

	for(int i =0;i<boom_size;i++)
	{
		if (!under[i])
			end = false;
	}

	if (end)
		time += 1 * share.delta;

	if(time >= 2)
		a += 0.4 * share.delta;
}

void BOOM::update()
{
	exploding();

	if (explosion)
	{
		collision();

		for (int i = 0; i < boom_size; i++)
		{
			boom_hit[i] = RectF(boom_pos[i], 8, 8);
			boom_w[i] = boom_pos[i].x + boom_hit[i].w;
			boom_h[i] = boom_pos[i].y + boom_hit[i].h;
		}
	}
}

void BOOM::draw()
{
	if (explosion)
	{
		for (int i = 0; i < boom_size; i++)
		{
			boom_hit[i].draw();
			boom[i].draw(boom_pos[i]);
		}
	}
}

void BOOM::credit()
{

	POX[0].drawAt(400, 170, ColorF(1.0, a));
	gimmick.font[2](U"End Game : ESC").drawAt(400, 250, ColorF(0.0, a));

}
