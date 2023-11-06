#pragma once
#include <Siv3D.hpp>

typedef struct
{

	double delta;

}Share;

extern Share share;

void definition();

void init();
void update();
void draw();

Vec2 move(Vec2 vec);
