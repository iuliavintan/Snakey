#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"


void Snake::Draw(){
    for(int i=0; i<body.size(); i++){
        Rectangle bucata = Rectangle{body[i].x * cellSize +offset, body[i].y * cellSize+offset, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(bucata, 0.5, body.size(), SNAKE);
    }
}

void Snake::updatePos(){
    if(addSeg){
        addSeg=false;
    }else{
        body.pop_back();
    }
    body.push_front(Vector2Add(body[0], direction));
}

void Snake::Reset(){
    body={Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
}
