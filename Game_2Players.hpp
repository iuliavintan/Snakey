#include<iostream>
#include<raylib.h>
#include"Game.hpp"
#include"Food.hpp"
#include"Snake.hpp"

#ifndef GAME_2PLAYERS_HPP
#define GAME_2PLAYERS_HPP

class Game_2Players:public Game{

    public:
        Game_2Players();

        void Draw() override;

        void Update() override;

        void CheckCollisionWithOtherSnake();

        void CheckCollisionWithTail()override;

        void CheckCollisionWithEdges()override;

        void CheckCollisionWithFood()override;

        Snake& GetSnake1();

        Snake& GetSnake2();

        void GameOver()override;
        
        int GetScore2();

    private:
        Snake snake2;
        int score1;
        int score2;

};

#endif