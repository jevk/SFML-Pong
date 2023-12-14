#include "Ball.h"
#include <iostream>

void Ball::setDirection(int x, int y)
{
	direction[0] = x;
	direction[1] = y;
}

int* Ball::getDirection()
{
	return direction;
}

void Ball::setSpeed(int speed)
{
	this->speed = speed;
}

int Ball::getSpeed()
{
	return speed;
}

void Ball::move()
{
	position[0] += direction[0] * speed;
	position[1] += direction[1] * speed;
	shape.setPosition(Vector2f(position[0], position[1]));
}

void Ball::bounceX()
{
	direction[0] *= -1;
}

void Ball::bounceY()
{
	direction[1] *= -1;
}
void Ball::setPosition(int x, int y)
{
	position[0] = x;
	position[1] = y;
	shape.setPosition(Vector2f(x, y));
}
int* Ball::getPosition()
{
	return position;
}

void Ball::setBounds(int width, int height)
{
	bounds[0] = width;
	bounds[1] = height;
	shape.setSize(Vector2f(width, height));
}
int* Ball::getBounds()
{
	return bounds;
}

void Ball::setFillColor(Color color)
{
	shape.setFillColor(color);
}
Color Ball::getFillColor()
{
	return shape.getFillColor();
}

Ball::Ball(int x, int y, int width, int height, int speed)
{
	this->speed = speed;
	direction[0] = 1;
	direction[1] = 1;

	shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(width, height));
}