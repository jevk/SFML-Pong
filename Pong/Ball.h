#pragma once
#include "Object.h"
class Ball
{
private:
    int direction[2];
    float speed;
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
	void setSpeed(float speed);
	float getSpeed();
	void addSpeed(float speed);
	void bounceX();
	void bounceY();
};

