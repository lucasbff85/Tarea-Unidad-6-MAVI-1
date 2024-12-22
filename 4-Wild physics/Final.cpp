#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Final.h"

using namespace sf;

Final::Final() {
	_win = false;
	_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Gunman");




	_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
	_text.setFont(_font);
	_text.setPosition(50, 50);
	_text.setCharacterSize(50.0f);
	_text.setFillColor(Color::Red);
	_text.setPosition(200, 650);


}


void Final::ProcesarEventos() {

	Event evt;
	while (_wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			_wnd->close();
		}
		if (evt.type == Event::KeyPressed) {
			if (evt.key.code == Keyboard::Escape)
				_exit = true;
		}
	}
}

void Final::Loop() {
	while (_wnd->isOpen()) {
		if (!_exit) {
			ProcesarEventos();
			actualizarTexto();
			Dibujar();
		}
		else {
			_wnd->close();
		}

	}
}


void Final::actualizarTexto() {
	if (_win) {
		_text.setString("BUENA PARTIDA!!\n\nLograste destruir 10 bolas...\n\n"
			"Tus puntos: " + std::to_string(_puntos) + "\nTus vidas : " + std::to_string(_vidas));
	}
	else {
		_text.setString("PERDISTE!!! ... te quedaste sin vidas.\n\n-Mejor suerte la próxima vez\n\n"
			"Tus puntos: " + std::to_string(_puntos) + "\nTus vidas : " + std::to_string(_vidas));
	}
}

void Final::Dibujar() {
	_wnd->clear();
	_wnd->draw(_text);
	_wnd->display();
}

void Final::setWin(bool valor) {
	_win = valor;
}

void Final::setPuntos(int puntos) {
	_puntos = puntos;
}

void Final::setVidas(int vidas) {
	_vidas = vidas;
}
