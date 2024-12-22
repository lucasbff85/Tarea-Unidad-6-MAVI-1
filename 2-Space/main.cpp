#include <SFML/Window.hpp>
#include <SFML/graphics.hpp>
using namespace sf;

int main() {

	RenderWindow window(VideoMode(800, 600), "Space");

    CircleShape ball(20.0f);
    ball.setFillColor(Color::Green);
    Vector2f position(400, 300);
    Vector2f acceleration(0,0);
    Vector2f velocity(0, 0);
    const float maxSpeed = 500.0f;
    const float maxAccel = 3.0f;

    std::string mensaje = "Utilizar flechas de dirección para mover la pelota";

    Text texto;
    Font fuente;

    fuente.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
    texto.setFont(fuente);
    texto.setCharacterSize(20);
    texto.setFillColor(Color::Red);
    texto.setString(mensaje);

	// Tiempo por fotograma
	const float deltaTime = 0.1f / 60.0f; // Suponemos que el juego se ejecuta a 60FPS

	//Bucle principal del juego
	while (window.isOpen()) {
		Event event;
		


        // Procesar eventos
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); 
        }

        //Utilizo un límite de aceleración para observar mejor el comportamiento
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (acceleration.y > -maxAccel)
                acceleration.y -= 0.5f;
            acceleration.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (acceleration.y < maxAccel)
                acceleration.y += 0.5f;
            acceleration.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (acceleration.x < maxAccel)
                acceleration.x += 0.5f;
            acceleration.y = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (acceleration.x > -maxAccel)
                acceleration.x -= 0.5f;
            acceleration.y = 0;
        }


        //chequeo bordes para que reinicie posición
        if (position.x > 800)
            position.x = 0;
        if (position.x < 0)
            position.x = 800;
        if (position.y > 600)
            position.y = 0;
        if (position.y < 0)
            position.y = 600;
        




		window.clear();

        velocity.x += acceleration.x * deltaTime;
        velocity.y += acceleration.y * deltaTime;

        //le pongo un límite de velocidad para observar mejor el comportamiento
        if (abs(velocity.x) > maxSpeed)
            velocity.x = (velocity.x > 0 ? maxSpeed : -maxSpeed);
        if (abs(velocity.y) > maxSpeed)
            velocity.y = (velocity.y > 0 ? maxSpeed : -maxSpeed);

        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;


        ball.setPosition(position);
		window.draw(ball);
        window.draw(texto);



		window.display();

	}

	return 0;

}