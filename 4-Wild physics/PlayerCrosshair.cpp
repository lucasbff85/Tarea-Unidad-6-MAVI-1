#pragma once 
#include "stdafx.h" 
#include "PlayerCrosshair.h"

using namespace sf;

PlayerCrosshair::PlayerCrosshair() {

	_crossTex.loadFromFile("../Assets/crosshair.png");
	_crossSprite.setTexture(_crossTex);
	_crossSprite.setScale(0.05f, 0.05f);
	Vector2u size = _crossTex.getSize();
	_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
}

void PlayerCrosshair::Dibujar(RenderWindow* wnd) {
	wnd->draw(_crossSprite);
}

void PlayerCrosshair::Posicionar(float x, float y) {
	_crossSprite.setPosition(x, y);
}

Vector2f PlayerCrosshair::ObtenerPosicion() {
	return _crossSprite.getPosition();
}