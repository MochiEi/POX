#include <Siv3D.hpp>
#include "Share.h"
#include "pox.h"
#include "Block.h"
#include "boom.h"
#include "Map.h"

void MAP::init()
{
	wall << Rect{0, 0, 10, 600};
	wall << Rect{790, 0, 10, 600};
	wall << Rect{0, 0, 800, 10};
	wall << Rect{0, 590, 800, 10};
	wall << Rect{380, 510, 40, 80};
	
	wall_size = wall.size();

	for (int i = 0; i < wall_size; i++)
	{
		wall_w << wall[i].x + wall[i].w;
		wall_h << wall[i].y + wall[i].h;
	}
}

void MAP::update()
{

}

void MAP::draw() const
{
	for (int i = 0; i < wall_size; i++)
	{
		wall[i].draw(ColorF(0.0));
	}
}
