#pragma once
#include "Share.h"

class PHRASE
{
public:

	void init();

	void update();

	void draw();

	void window();

	void execution();

	Array<TextureRegion> phrase;
	Array<Vec2> phrase_pos;
	size_t phrase_size;

	Array<double> phrase_a;

	bool select;

	bool V;//動詞
	bool N;//名詞

	bool Create_BOX;
	bool Break_BOX;
	bool Create_POX;
	bool Break_POX;
};

extern PHRASE phrase;
