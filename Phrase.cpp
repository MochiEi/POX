#include "Phrase.h"

void PHRASE::init()
{
	Texture Phrase0(U"example/pox/text_create.png", TextureDesc::Mipped);
	Texture Phrase1(U"example/pox/text_break.png", TextureDesc::Mipped);
	Texture Phrase2(U"example/pox/text_box.png", TextureDesc::Mipped);
	Texture Phrase3(U"example/pox/text_pox.png", TextureDesc::Mipped);
	Texture Phrase4(U"example/pox/text_box1.png", TextureDesc::Mipped);
	Texture Phrase5(U"example/pox/text_pox1.png", TextureDesc::Mipped);

	phrase << Phrase0;
	phrase << Phrase1;
	phrase << Phrase2;
	phrase << Phrase3;
	phrase << Phrase4;
	phrase << Phrase5;

	phrase_pos << Vec2(10, 40);
	phrase_pos << Vec2(10, 78);
	phrase_pos << Vec2(10, 136);
	phrase_pos << Vec2(10, 174);
	phrase_pos << Vec2(10, 244);

	phrase_size = phrase_pos.size();

	select = false;

	V = false;
	N = false;

	Create_BOX = false;
	Break_BOX = false;
	Create_POX = false;
	Break_POX = false;

	for (int i = 0; i < 4; i++)
		phrase_a << 1.0;
}

void PHRASE::window()
{
	if (Key1.down())
		select = false;
	if (Key2.down())
		select = true;

	if (!select)
	{
		if (KeyUp.down() && !boton.phrase[1])
		{
			V = !V;
		}
		if (KeyDown.down() && !boton.phrase[1])
		{
			V = !V;
		}
	}

	if (select)
	{
		if (KeyUp.down() && !boton.phrase[2])
		{
			N = !N;
		}
		if (KeyDown.down() && !boton.phrase[2])
		{
			N = !N;
		}
	}

	for (int i = 0; i < 4; i++)
		phrase_a[i] = 1.0;

	V ? phrase_a[0] = 0.3 : phrase_a[1] = 0.3;
	N ? phrase_a[2] = 0.3 : phrase_a[3] = 0.3;

}

void PHRASE::execution()
{
	Create_BOX = false;
	Break_BOX = false;
	Create_POX = false;
	Break_POX = false;

	if (KeyEnter.down() && !V && !N)
		Create_BOX = true;
	if (KeyEnter.down() && V && !N)
		Break_BOX = true;
	if (KeyEnter.down() && !V && N)
		Create_POX = true;
	if (KeyEnter.down() && V && N)
		Break_POX = true;
}

void PHRASE::update()
{
	if (gimmick.TabKey)
	{
		window();
	}

	execution();
}

void PHRASE::draw()
{
	if (!boton.phrase[0]) {
		phrase[0].draw(phrase_pos[0], ColorF(1.0, phrase_a[0]));
		phrase[2].draw(phrase_pos[2], ColorF(1.0, phrase_a[2]));
	}
	if (!boton.phrase[1]) {
		phrase[1].draw(phrase_pos[1], ColorF(1.0, phrase_a[1]));
	}
	if (!boton.phrase[2]) {
		phrase[3].draw(phrase_pos[3], ColorF(1.0, phrase_a[3]));
	}

	if (!boton.phrase[0])
	{
		if (!V)
			phrase[0].draw(phrase_pos[4]);
		if (V)
			phrase[1].draw(phrase_pos[4]);
		if (!N)
			phrase[4].draw(phrase_pos[4]);
		if (N)
			phrase[5].draw(phrase_pos[4]);
	}
}
