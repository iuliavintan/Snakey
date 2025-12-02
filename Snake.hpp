#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake{

	public:
		Snake();

		const std::deque<Vector2>& GetBody() const;
		void SetBody(const std::deque<Vector2>& newBody);

		Vector2 GetDirection() const;
		void SetDirection(const Vector2& newDirection);

		bool GetAddSegment() const;
		void SetAddSegment(bool value);


		void Draw();

		void updatePos();

		void Reset(Vector2 body_coord, Vector2 dir);

		

	private:
		std::deque<Vector2> body;
		Vector2 direction;
		bool addSeg;
};

#endif
