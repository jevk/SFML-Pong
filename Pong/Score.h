#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Score
{
	private:
	int score;
	int position[2];
	int bounds[2];
	public:
		Text text;
		Score(int x, int y, int width, int height);
		void setPosition(int x, int y);
		int* getPosition();
		void setBounds(int width, int height);
		int* getBounds();
		void setFillColor(Color color);
		Color getFillColor();
		void setScore(int score);
		int getScore();
		void addScore(int score);
		void setText(String text);
		void setFont(Font font);
};

