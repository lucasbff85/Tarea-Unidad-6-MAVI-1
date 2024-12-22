#pragma once
#include "stdafx.h"
#include "Bola.h"

using namespace sf;

Bola::Bola() :ball(55.0f) {
	tipo = rand() % 3 + 1;
	_derrotado = false;


	//configuro el origen en el centro
	ball.setOrigin(ball.getGlobalBounds().width / 2, ball.getGlobalBounds().height / 2);


}

void Bola::Dibujar(RenderWindow* wnd) {
	ball.setPosition(position);
	ball.setFillColor(Color::Red);
	wnd->draw(ball);
}

void Bola::aparecer(RenderWindow* wnd) {
	tipo = rand() % 3 + 1;
	switch (tipo) {
	case 1:
		setVelocidad(20, 0);
		position.x = 0;
		position.y = rand() % wnd->getSize().y;
		break;

	case 2:
		setVelocidad(-20, 0);
		position.x = wnd->getSize().x;
		position.y = rand() % wnd->getSize().y;
		break;

	case 3:
		setVelocidad(0, 20);
		position.x = rand() % wnd->getSize().x;
		position.y = 0;
	}
	ball.setPosition(position);

}

void Bola::mover(RenderWindow* wnd) {
	//aparecer(wnd);

	if (tipo == 1) {
		if (position.x > wnd->getSize().x)
			aparecer(wnd);
	}
	else if (tipo == 2) {
		if (position.x < 0)
			aparecer(wnd);
	}
	else {
		if (position.y > wnd->getSize().y)
			aparecer(wnd);
	}
	position.x += velocidad.x * deltaTime;
	position.y += velocidad.y * deltaTime;
	ball.setPosition(position);
}

// Comprobar si el mouse está encima de la bola
bool Bola::EstaEncima(float x, float y) {
	FloatRect bounds = ball.getGlobalBounds();
	return bounds.contains(x, y);
}

Vector2f Bola::posicion() {
	return ball.getPosition();
}

void Bola::setVelocidad(int valor1, int valor2) {
	velocidad.x = valor1;
	velocidad.y = valor2;
}
