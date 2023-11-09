#include "Share.h"

Share share;
POX pox;
BLOCK block;
BOOM boom;
MAP map;

void definition()
{
	share.delta = Scene::DeltaTime();
}

void init()
{
	pox.init();
	boom.init();
	block.init();
	map.init();
}

void update()
{
	if (pox.pox_num != 0)
	{
		pox.upate();
		block.update();
	}

	boom.update();
	map.update();
}

void draw()
{
	pox.draw();
	boom.draw();
	block.draw();
	map.draw();
}

Vec2 move(Vec2 vec)
{
	if (KeyD.pressed())
	{
		vec.x += 100 * share.delta;
	}
	if (KeyA.pressed())
	{
		vec.x -= 100 * share.delta;
	}

	Vec2 Vec{ vec.x , vec.y };

	return Vec;
}
