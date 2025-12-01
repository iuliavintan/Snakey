#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>

#ifndef FOOD_HPP
#define FOOD_HPP

class Food{

	public:
		Vector2 position;
		Texture2D texture;

		Food(std::deque<Vector2> snakeBody);

		~Food();

		void Draw();

		Vector2 generateRandomCell();

		Vector2 genrateRandomPos(std::deque<Vector2> snakeBody);
};

#endif