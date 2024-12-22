#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"

using namespace sf;


class Final {
	Font _font;
	Text _text;
	RenderWindow* _wnd;
	bool _win;
	bool _exit = false;
	int _puntos = 0;
	int _vidas = 0;


public:
	Final();
	void ProcesarEventos();
	void Loop();
	void actualizarTexto();
	void Dibujar();
	void setWin(bool valor);
	void setPuntos(int puntos);
	void setVidas(int vidas);
};
