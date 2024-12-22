#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"

using namespace sf;


class Inicio {
	Font _font;
	Text _text;
	RenderWindow* _wnd;
	bool _play;

public:
	Inicio();
	void ProcesarEventos();
	void Loop();
	void Dibujar();
};
