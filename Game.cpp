#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"
#include"Game.hpp"

Game::Game()
    : snake(),
      food(snake.GetBody()),
      running(true),
      score(0),
      high_score(0)
{}

Snake& Game::GetSnake(){
    return snake;
}

const Snake& Game::GetSnake() const{
    return snake;
}

bool Game::IsRunning() const{
    return running;
}

void Game::SetRunning(bool value){
    running = value;
}

int Game::GetScore() const{
    return score;
}

void Game::SetScore(int value){
    score = value;
}

int Game::GetHighScore() const{
    return high_score;
}

void Game::SetHighScore(int value){
    high_score = value;
}

void Game::Draw(){
    food.Draw();
    snake.Draw();
    if(!running){
        DrawText("GAME OVER:(", 300, offset+cellSize*cellCount+10 ,40 , SNAKE);

    }
}

void Game::Update(){
    if(running){
        snake.updatePos();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
        CheckHighScore();
    }
}

void Game::CheckCollisionWithFood(){
    if(Vector2Equals(snake.GetBody()[0], food.GetPosition())){
        food.SetPosition(food.genrateRandomPos(snake.GetBody()));
        snake.SetAddSegment(true);
        score++;
    }
}

void Game::CheckCollisionWithEdges(){
    if(snake.GetBody()[0].x==cellCount || snake.GetBody()[0].x==-1){
        GameOver();
    }
    if(snake.GetBody()[0].y==cellCount || snake.GetBody()[0].y==-1){
        GameOver();
    }
}

void Game::CheckCollisionWithTail(){
    std::deque<Vector2> headless = snake.GetBody();
    headless.pop_front();
    for(int i=0; i<headless.size(); i++)
    {
        if(headless[i]==snake.GetBody()[0])
            GameOver();
    }
}

void Game::CheckHighScore(){
    if(high_score<score)
        high_score=score;
}

void Game::GameOver(){
    snake.Reset({6, 9}, {1,0});
    food.SetPosition(food.genrateRandomPos(snake.GetBody()));
    running = false;
    score = 0;
    // DrawText("GAME OVER:(", offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
}


