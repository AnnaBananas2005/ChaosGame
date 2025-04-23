#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/FileInputStream.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;

	Font newFont;

	if (!newFont.loadFromFile("Desktop/cisp400/Chaos_Game/arial.ttf"))
	{
		//error
	}

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		//text and font (done by Fernanda)
		Text newText("Please choose three points", newFont);
		newText.setCharacterSize(522);
		newText.setFillColor(Color::Red);
		newText.setStyle(Text::Bold);
		newText.setPosition(50, 50);
		window.draw(newText);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					if (vertices.size() < 3)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
					else if (points.size() == 0)
					{
						///fourth click
						///push back to points vector
						points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/

		if (points.size() > 0)
		{
			///Chaos Math (done by Anna)
			///generate more point(s)
			Vector2f pt1 = vertices[0];
			Vector2f pt2 = vertices[1];
			Vector2f pt3 = vertices[2];
			///select random vertex
			///calculate midpoint between random vertex and the last point in the vector
			///push back the newly generated coord.
			Vector2f lastPt = points.back();
			int newRand = (rand() % 3) + 1;

			Vector2f vertex = vertices[newRand];

			Vector2f newPt;
			newPt.x = (lastPt.x + vertex.x) / 2.0;
			newPt.y = (lastPt.y + vertex.y) / 2.0;

			points.push_back(newPt);

		}

		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for (int i = 0; i < vertices.size(); i++)
		{
			RectangleShape rect(Vector2f(10, 10));
			rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
			rect.setFillColor(Color::Blue);
			window.draw(rect);
		}
		///TODO:  Draw points
		//drawing code done by Fernanda 
		window.clear();
		for (int i = 0; i < points.size(); i++)
		{
			RectangleShape rect(Vector2f(10, 10));
			rect.setPosition(Vector2f(points[i].x, points[i].y));
			rect.setFillColor(Color::Blue);
			window.draw(rect);
		}
		window.display();
	}
	return 0;
}
