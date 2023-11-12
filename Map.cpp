#include "Map.h"

void MAP::init()
{

	//Gimmick_boton01
	wall << Rect{500, 434, 164, 166};
	wall << Rect{500, 434, 20, 20};
	wall << Rect{644, 434, 20, 20};
	wall << Rect{500, 434, 20, 20};
	wall << Rect{644, 434, 20, 20};
	wall << Rect{520, 454, 124, 126};
	wall << Rect{560, 0, 20, 181};

	//Gimmick_boton02
	wall << Rect{580, 161, 220, 20};
	wall << Rect{133, 559, 40, 39};
	wall << Rect{291, 559, 40, 39};

	//Tab
	wall << Rect{5, 20, 330, 275};

	//固定
	wall << Rect{0, 0, 10, 600};
	wall << Rect{790, 0, 10, 600};
	wall << Rect{0, 0, 800, 10};
	wall << Rect{0, 590, 800, 10};
	wall << Rect{380, 512, 40, 78};

	
	wall_size = wall.size();

	for (int i = 0; i < wall_size; i++)
	{
		wall_w << wall[i].x + wall[i].w;
		wall_h << wall[i].y + wall[i].h;
	}
}

void MAP::update()
{
	for (int i = 0; i < wall_size; i++)
	{
		wall_w[i] = wall[i].x + wall[i].w;
		wall_h[i] = wall[i].y + wall[i].h;
	}
}

void MAP::draw() const
{
	for (int i = 0; i < wall_size; i++)
	{
		if (i != 5 && i != 10)
			wall[i].draw(ColorF(0.0));

		if (i == 5)
			wall[i].draw();

		if (i == 10)
			wall[i].drawFrame(1,5, ColorF(0.0));
	}
	
}
