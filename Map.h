#pragma once
#include "Share.h"

class MAP
{
public:

	void init();

	void update();

	void draw() const;


	Array<Rect> wall;
	size_t wall_size;

	Array<double> wall_w;
	Array<double> wall_h;

private:
};

extern MAP map;
