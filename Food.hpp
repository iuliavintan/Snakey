#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>

#ifndef FOOD_HPP
#define FOOD_HPP

class Food{

	public:
		Food(std::deque<Vector2> snakeBody);

		~Food();

		void Draw();

		Vector2 generateRandomCell();

		Vector2 genrateRandomPos(std::deque<Vector2> snakeBody);

		Vector2 GetPosition() const;
		void SetPosition(const Vector2& newPosition);

	private:
		Vector2 position;
		Texture2D texture;
};

#endif
