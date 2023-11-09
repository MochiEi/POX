#include "Share.h"

void Main()
{
	Scene::SetBackground(Palette::White);

	init();

	while (System::Update())
	{
		ClearPrint();
		definition();

		update();
		draw();
	}
}
