#include<iostream>
#include<raylib.h>

int main(void){
	
	std::cout<<"Let's start!"<<std::endl;
	InitWindow(750, 750, "SnakeySnake");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Let's start!", 300, 350, 30, RAYWHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
