#include "Share.h"

Share share;
POX pox;
BLOCK block;
BOTON boton;
BOOM boom;
MAP map;
GIMMICK gimmick;
PHRASE phrase;

void definition()
{
	share.delta = Scene::DeltaTime();
}

void init()
{
	pox.init();
	boom.init();
	block.init();
	boton.init();
	phrase.init();
	map.init();
	gimmick.init();
}

void update()
{
	if (pox.pox_num != 0)
	gimmick.update();

	if (gimmick.start)
	{
		if (gimmick.tabkey >= 308)
		{
			if (pox.pox_num != 0)
			{
				pox.upate();
				block.update();
				boton.update();
			}

			boom.update();
		}

		phrase.update();
		map.update();
	}
}

void draw()
{
	pox.draw();
	boom.draw();
	block.draw();
	boton.draw();
	phrase.draw();
	map.draw();
	gimmick.draw();
	boom.credit();
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
