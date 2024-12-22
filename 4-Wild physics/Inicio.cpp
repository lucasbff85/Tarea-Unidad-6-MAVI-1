#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Inicio.h"

using namespace sf;

Inicio::Inicio() {
	_play = false;
	_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Physics");



	_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
	_text.setFont(_font);
	_text.setPosition(50, 50);
	_text.setCharacterSize(50.0f);
	_text.setFillColor(Color::Cyan);
	_text.setString("UNIDAD 6 MODELOS Y ALGORITMOS PARA VIDEOJUEGOS I\n Instrucciones:\n-Se apunta y dispara con el puntero del ratón\n"
		"-Cada disparo acertado a una bola suma 1 punto\n"
		"\n"
		"-Cada disparo que fallas resta 1 vida y 2 puntos\n"
		"-Debes destruir 10 bolas\n"
		"-Se pierde si gastamos 3 vidas\n\n\n"
		"PRESIONA BARRA ESPACIADORA PARA COMENZAR A JUGAR!!");
}


void Inicio::ProcesarEventos() {

	Event evt;
	while (_wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			_wnd->close();
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::Space)
				_play = true;
		}
	}
}

void Inicio::Loop() {
	while (_wnd->isOpen()) {
		if (!_play) {
			ProcesarEventos();
			Dibujar();
		}
		else {
			_wnd->close();
		}

	}
}

void Inicio::Dibujar() {
	_wnd->clear();
	_wnd->draw(_text);
	_wnd->display();
}
