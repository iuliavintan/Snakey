#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"

#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake{

	public:
		std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
		Vector2 direction=Vector2{1,0};
		bool addSeg=false;

		void Draw();

		void updatePos();

		void Reset();
};

#endif