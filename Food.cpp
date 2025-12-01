#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"


Food::Food(std::deque<Vector2> snakeBody){
			Image img=LoadImage("graphics/mar.png");
			ImageResize(&img, cellSize, cellSize);
			texture=LoadTextureFromImage(img);
			UnloadImage(img);
			position=genrateRandomPos(snakeBody);
		}

Food::~Food(){
			UnloadTexture(texture);
		}

void Food::Draw(){
			if (texture.id != 0) {
				DrawTexture(texture, offset+1 + position.x * cellSize, offset +1+ position.y * cellSize, RAYWHITE);
			}
		}

Vector2 Food::generateRandomCell(){
			float x = GetRandomValue(0, cellCount-1);
			float y = GetRandomValue(0, cellCount-1);
			return Vector2{x,y};
		}

Vector2 Food::genrateRandomPos(std::deque<Vector2> snakeBody){
			Vector2 position=generateRandomCell();
			while(ElementInDeque(position, snakeBody))
			{
				position=generateRandomCell();
			}
			return position;
		}   

