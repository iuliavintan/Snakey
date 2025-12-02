#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"

Snake::Snake()
    : body{Vector2{6,9}, Vector2{5,9}, Vector2{4,9}},
      direction{1,0},
      addSeg(false)
{}

void Snake::Draw(){
    for(int i=0; i<body.size(); i++){
        Rectangle bucata = Rectangle{body[i].x * cellSize +offset, body[i].y * cellSize+offset, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(bucata, 0.5, body.size(), SNAKE);
    }
}

void Snake::updatePos(){
    if(addSeg){
        addSeg = false;
    }else{
        body.pop_back();
    }
    body.push_front(Vector2Add(body[0], direction));
}

void Snake::Reset(Vector2 body_coord, Vector2 dir){
    body = {body_coord, Vector2Add(body_coord, {1,0}), Vector2Add(body_coord, {2,0})};
    direction = dir;
    addSeg = false;
}

const std::deque<Vector2>& Snake::GetBody() const{
    return body;
}

void Snake::SetBody(const std::deque<Vector2>& newBody){
    body = newBody;
}

Vector2 Snake::GetDirection() const{
    return direction;
}

void Snake::SetDirection(const Vector2& newDirection){
    direction = newDirection;
}

bool Snake::GetAddSegment() const{
    return addSeg;
}

void Snake::SetAddSegment(bool value){
    addSeg = value;
}
