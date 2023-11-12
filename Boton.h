#pragma once
#include "Share.h"

class BOTON
{
public:

	void init();

	void pushed();

	void update();

	void draw();

	Array<TextureRegion> boton;
	Array<Vec2> boton_pos;
	Array<RectF> boton_hit;
	size_t boton_size;

	Array<double> boton_w;
	Array<double> boton_h;

	Array<bool> push;

	Array<bool> phrase;

private:

};

extern BOTON boton;
