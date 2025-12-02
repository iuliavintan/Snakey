#include<iostream>
#include<raylib.h>
#include"Game.hpp"
#include"Food.hpp"
#include"Snake.hpp"
#include"Game_2Players.hpp"

Game_2Players::Game_2Players()
    :Game(),
    score1(0),
    snake2()
{
    snake2.SetBody({Vector2{18,15}, Vector2{19,15}, Vector2{20,15}});
    snake2.SetDirection(Vector2{-1,0});
}

void Game_2Players::Draw(){
    snake2.Draw();
    Game::Draw();
}

void Game_2Players::Update(){
    if(running){
        snake2.updatePos();
        CheckCollisionWithOtherSnake();
    }
    Game::Update();
}

void Game_2Players::CheckCollisionWithOtherSnake(){
    for(int i=0; i<snake.GetBody().size(); i++){
        if(snake2.GetBody()[0]==snake.GetBody()[i])
        {
            GameOver(); //snake2 looses
        }
    }

    for(int i=0; i<snake2.GetBody().size(); i++){
        if(snake.GetBody()[0]==snake2.GetBody()[i])
        {
            GameOver(); //snake looses
        }
    }
}

void Game_2Players::CheckCollisionWithTail(){
    std::deque<Vector2> headless = snake2.GetBody();
    headless.pop_front();
    for(int i=0; i<headless.size(); i++)
    {
        if(headless[i]==snake2.GetBody()[0])
            GameOver();
    }
    Game::CheckCollisionWithTail();
}

void Game_2Players::CheckCollisionWithEdges(){

    if(snake2.GetBody()[0].x==cellCount || snake2.GetBody()[0].x==-1){
        GameOver();
    }
    if(snake2.GetBody()[0].y==cellCount || snake2.GetBody()[0].y==-1){
        GameOver();
    }
    Game::CheckCollisionWithEdges();
}

void Game_2Players::CheckCollisionWithFood(){
    if(Vector2Equals(snake2.GetBody()[0], food.GetPosition())){
        food.SetPosition(food.genrateRandomPos(snake2.GetBody()));
        snake2.SetAddSegment(true);
        score2++;
    }

    Game::CheckCollisionWithFood();
}

Snake& Game_2Players::GetSnake1()
{
    return snake;
}

Snake& Game_2Players::GetSnake2()
{
    return snake2;
}

void Game_2Players::GameOver()
{
    snake2.Reset({18,20}, {-1,0});
    Game::GameOver();
}

int Game_2Players::GetScore2(){
    return score2;
}