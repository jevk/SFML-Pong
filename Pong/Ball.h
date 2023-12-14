#pragma once
#include "Object.h"
class Ball
{
private:
    int direction[2];
    int speed;
	int position[2];
	int bounds[2];

public:
    Ball(int x, int y, int width, int height, int speed);
	RectangleShape shape;

	void setPosition(int x, int y);
	int* getPosition();

	void setBounds(int width, int height);
	int* getBounds();

	void setFillColor(Color color);
	Color getFillColor();

	void move();
	void setDirection(int x, int y);
	int* getDirection();
	void setSpeed(int speed);
	int getSpeed();
	void bounceX();
	void bounceY();
};

