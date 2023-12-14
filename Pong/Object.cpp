#include "Object.h"

void Object::setPosition(int x, int y)
{
	position[0] = x;
	position[1] = y;
	shape.setPosition(Vector2f(x, y));
}
int* Object::getPosition()
{
	return position;
}

void Object::setBounds(int width, int height)
{
	bounds[0] = width;
	bounds[1] = height;
	shape.setSize(Vector2f(width, height));
}
int* Object::getBounds()
{
	return bounds;
}

void Object::setFillColor(Color color)
{
	shape.setFillColor(color);
}
Color Object::getFillColor()
{
	return shape.getFillColor();
}

void Object::move(int x, int y)
{
	position[0] += x;
	position[1] += y;
	shape.setPosition(Vector2f(position[0], position[1]));
}

Object::Object(int x, int y, int width, int height)
{
	position[0] = x;
	position[1] = y;
	bounds[0] = width;
	bounds[1] = height;
	shape.setPosition(Vector2f(x, y));
	shape.setSize(Vector2f(width, height));
}