#include "Gimmick.h"

void GIMMICK::init()
{
	start = false;
	start_0 = 172;
	start_1 = 100;

	boton0_01 = false;
	boton0_01_01 = 250;
	boton0_01_02 = 65;
	boton0_01_03 = 40;
	boton0_02 = 190;
	boton1_01 = 220;
	boton1_02 = 39;
	tabkey = 350;

	talk_a = 1.0;
	obstacle = false;
	TabKey = false;

	font << Font{ 15, Typeface::Medium };
	font << Font{ FontMethod::SDF, 20, Typeface::Medium };
	font << Font{ 20, Typeface::Medium };
}

void GIMMICK::Start()
{
	start_0 -= 100 * share.delta;

	if (start_0 != 0 && start_1 != 0) {
		pox.pox_move += 15 * share.delta;

		if (pox.pox_move >= 5) {
			pox.pox_move = 0;
		}
	}

	if (start_0 <= 0 && start_1 != 0) {
		pox.pox_move = 0;
	}

	/////////////////   上の処理が終わったら   /////////////////

	if (start_0 <= 0){
		start_0 = 0;
		start_1 -= 80 * share.delta;
	}
	if (start_1 <= 0) {
		start_1 = 0;

		if(pox.pox_num != 5)
		pox.pox_move = 4;
		pox.pox_num = 5;
	}

	/////////////////   上の処理が終わったら   /////////////////

	if (start_1 <= 0) {

		if(talk_time <= 10)
		{
			pox.pox_move -= 20 * share.delta;

			if (pox.pox_move <= 0) {
				pox.pox_move = 0;
				talk_time += 10 * share.delta;
			}
		}

		if (talk_time > 10)
		{
			pox.pox_move += 20 * share.delta;

			if (pox.pox_move >= 5) {
				pox.pox_num = 1;
				pox.pox_move = 0;
				talk_time = 0;
				start = true;
			}
		}
	}

	pox.pox_pos.x = 100 - start_0;
	map.wall[11].y = 0 - start_1;
}

void GIMMICK::Gimmick_boton()
{

	/////////////////  ボタン０が押されきっていない   /////////////////

	if (!boton.push[0] && !boton0_01)
	{
		boton0_01_03 += 80 * share.delta;

		if (boton0_01_03 >= 40)
			boton0_01_03 = 40;

		/////////////////   上の処理が終わったら   /////////////////

		if (boton0_01_03 >= 40)
			boton0_01_02 += 80 * share.delta;
		if (boton0_01_02 >= 65)
			boton0_01_02 = 65;

		/////////////////   上の処理が終わったら   /////////////////

		if (boton0_01_02 >= 65)
			boton0_01_01 += 80 * share.delta;
		if (boton0_01_01 >= 250)
			boton0_01_01 = 250;

	}

	/////////////////  ボタン０が押されている   /////////////////

	if (boton.push[0] || boton0_01)
	{
		boton0_01_01 -= 80 * share.delta;

		if (boton0_01_01 <= 0)
			boton0_01_01 = 0;

		/////////////////   上の処理が終わったら   /////////////////

		if (boton0_01_01 <= 0)
			boton0_01_02 -= 80 * share.delta;
		if (boton0_01_02 <= 0)
			boton0_01_02 = 0;

		/////////////////   上の処理が終わったら   /////////////////

		if (boton0_01_02 <= 0)
			boton0_01_03 -= 80 * share.delta;
		if (boton0_01_03 <= 0)
			boton0_01_03 = 0;

		/////////////////   処理が全て終わったらロック   /////////////////

		if (boton0_01_03 <= 0) {
			boton0_01 = true;
		}
	}

	boton.boton_pos[1].y = 414 + boton0_01_01;

	map.wall[2].x = 644 - boton0_01_02;

	map.wall[0].y = 434 + boton0_01_01;
	map.wall[1].y = 434 + boton0_01_01 - boton0_01_03;
	map.wall[2].y = 434 + boton0_01_01 - boton0_01_03;
	map.wall[3].y = 434 + boton0_01_01 - boton0_01_03;
	map.wall[4].y = 434 + boton0_01_01 - boton0_01_03;
	map.wall[5].y = 454 + boton0_01_01;

	map.wall[1].w = 20 + boton0_01_02;
	map.wall[2].w = 20 + boton0_01_02;

	map.wall[3].h = 20 + boton0_01_03;
	map.wall[4].h = 20 + boton0_01_03;

	/////////////////  ボタン０が押されている or 押されれていない   /////////////////

	boton.push[0] ? boton0_02 -= 80 * share.delta : boton0_02 += 80 * share.delta;

	if (boton0_02 >= 190)
		boton0_02 = 190;
	if (boton0_02 <= 0)
		boton0_02 = 0;

	map.wall[6].y = 0 - boton0_02;

	/////////////////  ボタン１が押されている or 押されれていない   /////////////////

	boton.push[1] ? boton1_01 -= 80 * share.delta : boton1_01 += 80 * share.delta;

	if (boton1_01 <= 0)
		boton1_01 = 0;
	if (boton1_01 >= 220)
		boton1_01 = 220;

	boton.push[1] ? boton1_02 -= 80 * share.delta : boton1_02 += 80 * share.delta;

	if (boton1_02 <= 0)
		boton1_02 = 0;
	if (boton1_02 >= 39)
		boton1_02 = 39;

	boton.boton_pos[2].x = 630 + boton1_01;

	map.wall[7].x = 580 + boton1_01;

	map.wall[8].y = 551 + boton1_02;
	map.wall[9].y = 551 + boton1_02;
	////////////////   フレーズウィンドウ   /////////////////

	TabKey ? tabkey -= 1000 * share.delta : tabkey += 1000 * share.delta;

	if (tabkey <= 0)
		tabkey = 0;
	if (tabkey >= 350)
		tabkey = 350;

	map.wall[10].x = 5 - tabkey;
	for (int i = 0; i < phrase.phrase_size; i++)
		phrase.phrase_pos[i].x = 10 - tabkey;
}

void GIMMICK::window()
{
	if (KeyTab.down())
		TabKey = !TabKey;
}

void GIMMICK::talk()
{
	if (phrase.Create_POX)
		obstacle = true;

	if (obstacle) {
		talk_time += 10 * share.delta;
		if (talk_time >= 5)
		{
			talk_a -= 2 * share.delta;

			if (talk_a <= 0.0) {
				talk_a = 1.0;
				talk_time = 0;
				obstacle = false;
			}
		}
	}

	if (new_phrase) {
		talk_time += 10 * share.delta;
		if (talk_time >= 15)
		{
			talk_a -= 2 * share.delta;

			if (talk_a <= 0.0) {
				talk_a = 1.0;
				talk_time = 0;
				new_phrase = false;
			}
		}
	}

	//Print << talk_a;
	//Print << talk_time;
}

void GIMMICK::update()
{
	if (start)
	{
		window();
	}
	if (!start)
	{
		Start();
	}

	talk();
	Gimmick_boton();
}

void GIMMICK::draw()
{
	if (obstacle) {
		font[1](U"no").draw(TextStyle::Outline(0.1, ColorF(1.0)), pox.pox_pos.x - 33, pox.pox_pos.y, ColorF(0.0, talk_a));
	}
	if (new_phrase) {
		font[1](U"new phrase").draw(TextStyle::Outline(0.1, ColorF(1.0)), pox.pox_pos.x - 120, pox.pox_pos.y, ColorF(0.0, talk_a));
	}

	boton0_01 ? font[0](U"lock").draw(518, 432 + boton0_01_01) : font[0](U"lock").draw(518, 432 + boton0_01_01, ColorF(0.4));

	/////////////////   キーコンフィグ   /////////////////

	font[0](U"D >> \n<< A").draw(382, 512);
	font[0](U"　Key Config").draw(527, 462 + boton0_01_01, ColorF(0.0));
	font[0](U"Space : Jump").draw(525, 492 + boton0_01_01, ColorF(0.0));
	font[0](U"Tab : Inventory").draw(525, 517 + boton0_01_01, ColorF(0.0));
	font[0](U"Enter : Action").draw(525, 542 + boton0_01_01, ColorF(0.0));

	/////////////////   ウィンドウ   /////////////////

	if (!boton.phrase[0]) 
	{
		phrase.select ? font[0](U"\n1\n").draw(300 - tabkey, 40, ColorF(0.0)) : font[0](U"↑\n1\n↓").draw(300 - tabkey, 40, ColorF(0.0));
		phrase.select ? font[0](U"↑\n2\n↓").draw(300 - tabkey, 140, ColorF(0.0)) : font[0](U"\n2\n").draw(300 - tabkey, 140, ColorF(0.0));
	}
}
