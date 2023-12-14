#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Object
{
private:
	int position[2];
	int bounds[2];

public:
	RectangleShape shape;

	void setPosition(int x, int y);
	int* getPosition();

	void setBounds(int width, int height);
	int* getBounds();

	void setFillColor(Color color);
	Color getFillColor();

	void move(int x, int y);

	Object(int x, int y, int width, int height);
};
