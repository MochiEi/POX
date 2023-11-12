#pragma once
#include "Share.h"

class GIMMICK
{
public:

	void init();

	void update();

	void draw();


	void Start();

	void Gimmick_boton();

	void window();

	void talk();

	bool start;
	double start_0;
	double start_1;

	bool boton0_01;
	double boton0_01_01;
	double boton0_01_02;
	double boton0_01_03;
	double boton0_02;

	double boton1_01;
	double boton1_02;

	double tabkey;

	double talk_time;
	double talk_a;

	bool TabKey;
	bool obstacle;
	bool new_phrase;

	Array<Font> font;
};

extern GIMMICK gimmick;
