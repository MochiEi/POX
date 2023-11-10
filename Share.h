#pragma once
#include <Siv3D.hpp>
#include "pox.h"
#include "Block.h"
#include "boom.h"
#include "Map.h"
#include "Boton.h"

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
