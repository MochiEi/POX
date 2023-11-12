#include "Boton.h"

void BOTON::init()
{
	Texture Boton1(U"example/pox/boton1.png", TextureDesc::Mipped);
	Texture Boton2(U"example/pox/boton2.png", TextureDesc::Mipped);

	boton << Boton1;
	boton << Boton2;

	boton_pos << Vec2(200, 570);
	boton_pos << Vec2(550, 414);
	boton_pos << Vec2(630, 141);

	boton_size = boton_pos.size();

	for (int i = 0; i < boton_size; i++)
	{
		boton_hit << Rect(boton_pos[i].x + 11, boton_pos[i].y + 8, 42, 12);
		push << false;
	}

	phrase << true;
	phrase << true;
	phrase << true;
}

void BOTON::pushed()
{
	for (int i = 0; i < boton_size; i++)
	{
		push[i] = false;

		if (boton_hit[i].intersects(pox.pox_hit))
		{
			push[i] = true;

			if (phrase[i])
			{
				gimmick.new_phrase = true;
				phrase[i] = false;
			}
		}

		for (int j = 0; j < block.block_size; j++)
		{
			if (boton_hit[i].intersects(block.block_hit[j]))
			{
				push[i] = true;
			}
		}
	}
}

void BOTON::update()
{
	for (int i = 0; i < boton_size; i++)
	{
		boton_hit[i] = Rect(boton_pos[i].x + 11, boton_pos[i].y + 8, 42, 12);
	}
	pushed();
}

void BOTON::draw()
{
	for (int i = 0; i < boton_size; i++)
	{
		push[i] ? boton[1].draw(boton_pos[i]) : boton[0].draw(boton_pos[i]);
		//RectF(boton_hit[i]).draw(ColorF(0.0));
	}
}
