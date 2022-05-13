#include <iostream>
#include <SFML\Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "sfml tutorial", sf::Style::Close);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));
	sf::RectangleShape player(sf::Vector2f(90.0f, 100.0f));
	window.setFramerateLimit(30);
	//player.setFillColor(sf::Color::Blue);
	player.setOrigin(50.0f, 50.0f);
	player.setPosition(256.0f, 256.0f); 
	sf::Texture Playertexture;
	Playertexture.loadFromFile("tux.png");
	player.setTexture(&Playertexture);


	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
				/*case sf::Event::Resized:
					printf("the new window width %i and height is %i\n", evnt.size.width, evnt.size.height);
					break;*/
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) {
					//printf("%c", evnt.text.unicode);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				player.move(-1.2f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				player.move(1.2f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				player.move(0.0f, -1.2f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				player.move(0.0f, 1.2f);
			}
		}

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		window.draw(player);
		window.display();
	}



	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousepus = sf::Mouse::getPosition(window);
		player.setPosition((float)mousepus.x, static_cast<float>(mousepus.y));
	}
	*/




	return 0;
}
