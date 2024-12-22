#pragma once
#include "stdafx.h"

using namespace sf;

class Bola {
	CircleShape ball;
	Vector2f velocidad;
	int tipo;
	Vector2f position;
	const float deltaTime = 0.4f / 60.0f;


public:

	bool _derrotado;

	Bola();

	void Dibujar(RenderWindow* wnd);

	void aparecer(RenderWindow* wnd);

	void mover(RenderWindow* wnd);

	// Comprobar si el mouse está encima de la bola
	bool EstaEncima(float x, float y);

	Vector2f posicion();

	void setVelocidad(int valor1, int valor2);
};
