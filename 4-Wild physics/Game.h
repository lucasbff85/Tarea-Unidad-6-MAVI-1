#pragma once
#include "stdafx.h"
#include "Inicio.h"
#include "Cielo.h"
#include "Final.h"

using namespace sf;

class Game {
	Inicio* _inicio;
	Cielo* _cielo;
	Final* _final;
	Font _font;
	Text _text;
	int _puntos = 0;
	int _vidas = 0;
public:
	Game();
	void play();
};