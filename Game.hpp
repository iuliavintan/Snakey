#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
	public:
		Snake snake=Snake();
		Food food=Food(snake.body);
		bool running=true;
		int score=0;
		int high_score=0;

		void Draw();

		void Update();

		void CheckCollisionWithFood();

		void CheckCollisionWithEdges();

		void CheckCollisionWithTail();

		void CheckHighScore();

		void GameOver();
};

#endif