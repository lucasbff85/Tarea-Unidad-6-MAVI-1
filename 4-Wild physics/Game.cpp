#pragma once
#include "stdafx.h"
#include "Inicio.h"
#include "Cielo.h"
#include "Final.h"
#include "Game.h"

using namespace sf;

Game::Game() {
	_final = new Final();
	_cielo = new Cielo();
	_inicio = new Inicio();
}

void Game::play() {
	_inicio->Loop();
	_cielo->Loop();
	_puntos = _cielo->getPuntos();
	_vidas = _cielo->getVidas();
	_final->setPuntos(_puntos);
	_final->setVidas(_vidas);
	if (_puntos == 10)
		_final->setWin(true);
	_final->Loop();
}