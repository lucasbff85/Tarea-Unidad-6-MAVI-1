#include <SFML/Window.hpp>
#include <SFML/graphics.hpp>
using namespace sf;





int main() {

	RenderWindow window(VideoMode(800, 600), "Fast & Furious");


	Vector2f position(50.0f, 300.0f);
	float velocity = 20;
	//const float acceleration = 1.0f;
	const float maxVelocity = 200.0f;
	Vector2f posicionInicio(0.0f, 300.0f);
	CircleShape ball(20.0f);
	std::string mensaje = "La pelota alcanzó la velocidad máxima";
	


	Text texto;
	Font fuente;

	fuente.loadFromFile("../Fuentes/SpicyRice-Regular.ttf");
	texto.setFont(fuente);
	texto.setPosition(50, 100);
	texto.setCharacterSize(20);
	texto.setFillColor(Color::Red);
	

	
	// Tiempo por fotograma
	const float deltaTime = 0.3f / 60.0f; // Suponemos que el juego se ejecuta a 60FPS

	//Bucle principal del juego
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		position.x += velocity * deltaTime;


		window.clear();
		std::string velocimetro = "VELOCIDAD: " + std::to_string(velocity);
		texto.setString(velocimetro);
		
		if (position.x > 800) {
			ball.setPosition(posicionInicio);
			position = posicionInicio;
			velocity += 20;
		}
		else
			ball.setPosition(position);
		
		ball.setFillColor(Color::Green);
		window.draw(ball);
		window.draw(texto);

		if (velocity >= maxVelocity) {
			window.clear();
			texto.setString(mensaje);
			window.draw(texto);
			window.display();
			sf::sleep(sf::seconds(3)); // Pausa de 3 segundos
			window.close();
		}
			

		window.display();

	}

	return 0;

}