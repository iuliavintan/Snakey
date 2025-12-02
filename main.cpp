#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>
#include"defines.hpp"
#include"Food.hpp"
#include"Snake.hpp"
#include"Game.hpp"
#include"Game_2Players.hpp"

int main(void){
	
	std::cout<<"Let's start!"<<std::endl;
	int window_width=2*offset + cellSize*cellCount;
	InitWindow(window_width, window_width, "SnakeySnake");
	SetTargetFPS(100);

	GameState state=GameState::MENU;

    Rectangle startButton = { window_width/2.0f - 100, window_width/2.0f, 200, 50 };
	Rectangle playersButton = {window_width/2.0f - 100, window_width/2.0f + 100, 200, 50};

	{
		Game game=Game();
		Game_2Players game2=Game_2Players();
		while(!WindowShouldClose()){

			Vector2 mousePos=GetMousePosition();
			bool hoverStart=CheckCollisionPointRec(mousePos, startButton);
			bool hoverPlayers = CheckCollisionPointRec(mousePos, playersButton);


			if (state == GameState::MENU) {
				if (hoverStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					state = GameState::GAMEPLAY;
				}

				if (hoverPlayers && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
					state = GameState::TWO_PLAYERS;
				}
				
				
			}else if(state == GameState::GAMEPLAY){
				if(EventTriggered(0.2)){
					game.Update();
				}
				if((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.GetSnake().GetDirection().y!=1){
					game.GetSnake().SetDirection(Vector2{0,-1});	
					game.SetRunning(true);
				}else if((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.GetSnake().GetDirection().y!=-1){
					game.GetSnake().SetDirection(Vector2{0,1});
					game.SetRunning(true);
				}else if((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.GetSnake().GetDirection().x!=1){
					game.GetSnake().SetDirection(Vector2{-1,0});
					game.SetRunning(true);
				}else if((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.GetSnake().GetDirection().x!=-1){
					game.GetSnake().SetDirection(Vector2{1,0});
					game.SetRunning(true);
				}
			}else if(state==GameState::TWO_PLAYERS){
				if(EventTriggered(0.2)){
					game2.Update();
				}

				if(IsKeyPressed(KEY_UP) && game2.GetSnake1().GetDirection().y!=1){
					game2.GetSnake1().SetDirection(Vector2{0,-1});	
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_DOWN) && game2.GetSnake1().GetDirection().y!=-1){
					game2.GetSnake1().SetDirection(Vector2{0,1});
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_LEFT) && game2.GetSnake1().GetDirection().x!=1){
					game2.GetSnake1().SetDirection(Vector2{-1,0});
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_RIGHT)  && game2.GetSnake1().GetDirection().x!=-1){
					game2.GetSnake1().SetDirection(Vector2{1,0});
					game2.SetRunning(true);
				}

				if(IsKeyPressed(KEY_W) && game2.GetSnake2().GetDirection().y!=1){
					game2.GetSnake2().SetDirection(Vector2{0,-1});	
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_S) && game2.GetSnake2().GetDirection().y!=-1){
					game2.GetSnake2().SetDirection(Vector2{0,1});
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_A) && game2.GetSnake2().GetDirection().x!=1){
					game2.GetSnake2().SetDirection(Vector2{-1,0});
					game2.SetRunning(true);
				}else if(IsKeyPressed(KEY_D)  && game2.GetSnake2().GetDirection().x!=-1){
					game2.GetSnake2().SetDirection(Vector2{1,0});
					game2.SetRunning(true);
				}

			}

			BeginDrawing();
			ClearBackground(BACKGROUND);

			if(state==GameState::MENU){
				menu(window_width, startButton,playersButton, hoverStart, hoverPlayers);
			}
			else if(state==GameState::GAMEPLAY){
				game.Draw();
				DrawText(TextFormat("%i", game.GetScore()) ,offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
				DrawText(TextFormat("HighScore:%i", game.GetHighScore()), 600, 20, 40,SNAKE);
			}else{
				game2.Draw();
				DrawText(TextFormat("Player1:%i", game2.GetScore()) ,offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
				DrawText(TextFormat("Player2:%i", game2.GetScore2()), 630, offset+cellSize*cellCount+10 ,40 , SNAKE);
			}
	
			DrawRectangleLinesEx(Rectangle{(float)offset-5, (float)offset-5, (float)cellSize*cellCount+10, (float)cellSize*cellCount+10}, 5, SNAKE);
			DrawText("Snake", offset-5, 20, 40,SNAKE);
			
			EndDrawing();
		}
	}
	

	CloseWindow();
	return 0;
}
