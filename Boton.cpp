#include "Boton.h"

void BOTON::init()
{
	Texture Boton1(U"example/pox/boton1.png", TextureDesc::Mipped);
	Texture Boton2(U"example/pox/boton2.png", TextureDesc::Mipped);

	boton << Boton1;
	boton << Boton2;

	boton_pos << Vec2(100, 100);
	boton_pos << Vec2(100, 100);
	boton_pos << Vec2(100, 100);

	boton_size = boton_pos.size();

	for (int i = 0; i < boton_size; i++)
	{
		boton_hit << Rect(boton_pos[i].x + 11, boton_pos[i].y + 8, 42, 12);
		push << false;
	}
}

void BOTON::update()
{
}

void BOTON::draw()
{
	for (int i = 0; i < boton_size; i++)
	{
		push[i] ? boton[0].draw(boton_pos[i]) : boton[1].draw(boton_pos[i]);
		//RectF(boton_hit[i]).draw();
	}
}
