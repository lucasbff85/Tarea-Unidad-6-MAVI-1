#pragma once
#include "stdafx.h"
#include "Bola.h"
#include "Bang.h"
#include "PlayerCrosshair.h"
#include "Cielo.h"

using namespace sf;

Cielo::Cielo() {
	_puntos = 0;
	_vidas = 3;

	_wnd = new RenderWindow(VideoMode(1800, 1200, 32), "Wild Physics");
	_bang = new Bang();

	bola = new Bola();



	_font.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
	_text.setFont(_font);
	_text.setPosition(50, 50);
	_text.setCharacterSize(50.0f);
	_text.setFillColor(Color::Yellow);
	_text.setPosition(1100, 40);

	actualizarTexto();

	texCielo.loadFromFile("../Assets/cielo.jpg");
	spriteCielo.setTexture(texCielo);

	// Establecer el origen del sprite en su centro
	spriteCielo.setOrigin(spriteCielo.getGlobalBounds().width / 2,
		spriteCielo.getGlobalBounds().height / 2);

	spriteCielo.setPosition(900, 600);
	spriteCielo.setScale(3.0f, 3.0f);

	_player = new PlayerCrosshair();
	_wnd->setMouseCursorVisible(false);

	bola->aparecer(_wnd);

}



void Cielo::ProcesarEventos() {
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	Event evt;
	while (_wnd->pollEvent(evt)) {
		if (evt.type == Event::Closed) {
			_wnd->close();
		}
		if (evt.type == Event::MouseMoved) {
			_player->Posicionar(evt.mouseMove.x, evt.mouseMove.y);

		}
		if (evt.type == Event::MouseButtonPressed) {
			if (evt.mouseButton.button == Mouse::Button::Left)
				Disparar();
		}
	}
}


void Cielo::Loop() {
	sleep(seconds(0.8));
	while (_wnd->isOpen()) {
		if (_puntos < 10 && _vidas > 0) {
			bola->mover(_wnd);
			ProcesarEventos();
			Dibujar(_wnd);
		}
		else {
			_wnd->close();
		}

	}
}


void Cielo::Dibujar(RenderWindow* wnd) {
	wnd->clear();



	wnd->draw(spriteCielo);
	wnd->draw(_text);
	bola->Dibujar(_wnd);


	_bang->dibujar(_wnd);
	_player->Dibujar(_wnd);

	_wnd->display();
}





void Cielo::Disparar() {
	Vector2f playerPos = _player->ObtenerPosicion();
	_bang->disparar(playerPos);
	if (bola->EstaEncima(playerPos.x, playerPos.y)) {
		bola->aparecer(_wnd);
		_puntos++;
	}
	else {
		_vidas--;
		_puntos -= 2;
	}
	actualizarTexto();

}

int Cielo::getPuntos() {
	return _puntos;
}

int Cielo::getVidas() {
	return _vidas;
}

void Cielo::actualizarTexto() {
	_text.setString("VIDAS: " + std::to_string(_vidas) + "   PUNTOS: " + std::to_string(_puntos));
}

Cielo::~Cielo() {
	delete _player;
	delete _bang;
	delete _wnd;
}
