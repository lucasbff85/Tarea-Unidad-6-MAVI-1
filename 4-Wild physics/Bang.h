#pragma once
#include "stdafx.h";


using namespace sf;

class Bang {

	Texture tex_bang;
	Sprite sprite_bang;
	Clock clock;
	Time time = seconds(1);
	bool _isVisible = false;

	SoundBuffer _buffer;  // Buffer de sonido
	Sound _sound;         // Objeto de sonido

public:
	Bang();

	void disparar(Vector2f posicion);

	void dibujar(RenderWindow* wnd);



};