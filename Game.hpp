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
		Game();

		virtual void Draw();

		virtual void Update();

		virtual void CheckCollisionWithFood();

		virtual void CheckCollisionWithEdges();

		virtual void CheckCollisionWithTail();

		void CheckHighScore();

		virtual void GameOver();

		Snake& GetSnake();
		const Snake& GetSnake() const;

		bool IsRunning() const;
		void SetRunning(bool value);

		int GetScore() const;
		void SetScore(int value);

		int GetHighScore() const;
		void SetHighScore(int value);

	protected:
		Snake snake;
		Food food;
		bool running;
		int score;
		int high_score;
};

#endif
