#include "Main.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Started successfully!" << std::endl;
#endif

	sf::RenderWindow win2(sf::VideoMode(300,400), "2 windows baby");
	sf::RenderWindow window(sf::VideoMode(400, 300), "SFML works!");
#ifdef SFML_SYSTEM_WINDOWS
	__windowsHelper.setIcon(window.getSystemHandle());
	__windowsHelper.setIcon(win2.getSystemHandle());
#endif

	sf::CircleShape shape1(window.getSize().x/2);
	sf::CircleShape shape2(win2.getSize().x/2);
	shape1.setFillColor(sf::Color::White);
	shape2.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	sf::Texture s2txt;
	shapeTexture.loadFromFile("content/sfml.png");
	s2txt.loadFromFile("content/apple.png");
	shape1.setTexture(&shapeTexture);
	shape2.setTexture(&s2txt);

	//this chunk of code is where the program loops and can hold
	//	multiple windows open
	sf::Event event;
	sf::Event event2;

	while (window.isOpen() || win2.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		while (win2.pollEvent(event2))
		{
			if (event2.type == sf::Event::Closed){
				win2.close();
			}
		}

		if(!event.type == sf::Event::Closed){
			window.clear();
			window.draw(shape1);
			window.display();
		}
		if(!event2.type == sf::Event::Closed){
			win2.clear();
			win2.draw(shape2);
			win2.display();
		}
	}

	return 0;
}
