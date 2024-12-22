#pragma once
#include "stdafx.h"
#include "Bola.h"
#include "Bang.h"
#include "PlayerCrosshair.h"

using namespace sf;

class Cielo {
	RenderWindow* _wnd;
	PlayerCrosshair* _player;
	Bang* _bang;
	Clock _clock;
	int _puntos;
	int _vidas;
	Font _font;
	Text _text;
	Texture texCielo;
	Sprite spriteCielo;
	Bola* bola;

public:
	Cielo();
	void ProcesarEventos();
	void Loop();
	void Dibujar(RenderWindow* wnd);
	void Disparar();
	int getPuntos();
	int getVidas();
	void actualizarTexto();
	~Cielo();
};