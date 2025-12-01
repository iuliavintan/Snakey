#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"
#include"Game.hpp"



int main(void){
	
	std::cout<<"Let's start!"<<std::endl;
	int window_width=2*offset + cellSize*cellCount;
	InitWindow(window_width, window_width, "SnakeySnake");
	SetTargetFPS(100);

	GameState state=GameState::MENU;

    Rectangle startButton = { window_width/2.0f - 100, window_width/2.0f, 200, 50 };

	{
		Game game=Game();
		while(!WindowShouldClose()){

			Vector2 mousePos=GetMousePosition();
			bool hoverStart=CheckCollisionPointRec(mousePos, startButton);

			if (state == GameState::MENU) {
				if (hoverStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					state = GameState::GAMEPLAY;
				}

				if (IsKeyPressed(KEY_ENTER)) {
					state = GameState::GAMEPLAY;
				}
			}else{
				if(EventTriggered(0.2)){
					game.Update();
				}
				if((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.snake.direction.y!=1){
					game.snake.direction={0,-1};	
					game.running=true;
				}else if((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.snake.direction.y!=-1){
					game.snake.direction={0,1};
					game.running=true;
				}else if((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.snake.direction.x!=1){
					game.snake.direction={-1,0};
					game.running=true;
				}else if((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.snake.direction.x!=-1){
					game.snake.direction={1,0};
					game.running=true;
				}
			}

			BeginDrawing();
			ClearBackground(BACKGROUND);

			if(state==GameState::MENU){
				menu(window_width, startButton, hoverStart);
			}
			else if(state==GameState::GAMEPLAY){
				game.Draw();
				DrawText(TextFormat("%i", game.score) ,offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
				DrawText(TextFormat("HighScore:%i", game.high_score), 600, 20, 40,SNAKE);
			}
	
			DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5, (float)cellSize*cellCount+10, (float)cellSize*cellCount+10}, 5, SNAKE);
			DrawText("Snake", offset-5, 20, 40,SNAKE);
			
			EndDrawing();
		}
	}
	

	CloseWindow();
	return 0;
}
