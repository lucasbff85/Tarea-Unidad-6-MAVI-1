#include <SFML/Window.hpp>
#include <SFML/graphics.hpp>
using namespace sf;




int main() {
	RenderWindow window(VideoMode(800, 600), "Bounce");
	CircleShape ball(20.0f);

	//Definir la posici�n y velocidad inicial de la bola
	Vector2f position(300.0f, 0.0f);
	Vector2f velocity(0.0f, 0.0f);

	//Constante de gravedad para la ca�da libre
	const float gravity = 1.2f;

	// Tiempo por fotograma
	const float deltaTime = 0.4f / 60.0f; // Suponemos que el juego se ejecuta a 60FPS

	//Bucle principal del juego
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		

		velocity.y += gravity * deltaTime;
		position.y += velocity.y * deltaTime;


		// Comprobar si el objeto ha tocado el suelo
		if (position.y >= 500.0f) {
			position.y = 500.0f; // Asegurar que no atraviese el suelo
			velocity.y = -velocity.y * 0.7f; // Rebote con p�rdida de energ�a
		}


		window.clear();

		//Dibujar el objeto en su posici�n actual
		
		ball.setPosition(position);
		ball.setFillColor(Color::Red);
		window.draw(ball);

		//Mostrar todo en la ventana
		window.display();

	}

	return 0;

}