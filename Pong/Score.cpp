#include "Score.h"
#include <iostream>

Score::Score(int x, int y, int width, int height)
{
	position[0] = x;
	position[1] = y;
	bounds[0] = width;
	bounds[1] = height;
	text.setPosition(Vector2f(x, y));
	text.setCharacterSize(height);
	text.setFillColor(Color::White);
}

void Score::setPosition(int x, int y)
{
	position[0] = x;
	position[1] = y;
	text.setPosition(Vector2f(x, y));
}

int* Score::getPosition()
{
	return position;
}

void Score::setBounds(int width, int height)
{
	bounds[0] = width;
	bounds[1] = height;
	text.setCharacterSize(height);
}

int* Score::getBounds()
{
	return bounds;
}

void Score::setFillColor(Color color)
{
	text.setFillColor(color);
}
	
Color Score::getFillColor()
{
	return text.getFillColor();
}

void Score::setScore(int score)
{
	this->score = score;
	setText(std::to_string(this->score));
}

int Score::getScore()
{
	return score;
}

void Score::addScore(int score)
{
	this->score += score;
	setText(std::to_string(this->score));
}

void Score::setText(String text)
{
	this->text.setString(text);
}

void Score::setFont(Font font)
{
	this->text.setFont(font);
}