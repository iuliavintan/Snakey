#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"
#include"Game.hpp"



void Game::Draw(){
    food.Draw();
    snake.Draw();
    if(!running){
        DrawText("GAME OVER:(", 550, offset+cellSize*cellCount+10 ,40 , SNAKE);

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
    if(Vector2Equals(snake.body[0], food.position)){
        food.position=food.genrateRandomPos(snake.body);
        snake.addSeg=true;
        score++;
    }
}

void Game::CheckCollisionWithEdges(){
    if(snake.body[0].x==cellCount || snake.body[0].x==-1){
        GameOver();
    }
    if(snake.body[0].y==cellCount || snake.body[0].y==-1){
        GameOver();
    }
}

void Game::CheckCollisionWithTail(){
    std::deque<Vector2> headless=snake.body;
    headless.pop_front();
    for(int i=0; i<headless.size(); i++)
    {
        if(headless[i]==snake.body[0])
            GameOver();
    }
}

void Game::CheckHighScore(){
    if(high_score<score)
        high_score=score;
}

void Game::GameOver(){
    snake.Reset();
    food.position=food.genrateRandomPos(snake.body);
    running=false;
    score=0;
    // DrawText("GAME OVER:(", offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
}


