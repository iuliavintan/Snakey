#include<iostream>
#include<raylib.h>


Color BACKGROUND={10, 20, 40, 255};
Color UI = { 220, 240, 255, 255 };

int cellSize=30;
int cellCount=25;

class Food{

	public:
		Vector2 position;
		Texture2D texture;

		Food(){
			Image img=LoadImage("graphics/mar.png");
			ImageResize(&img, cellSize, cellSize);
			texture=LoadTextureFromImage(img);
			UnloadImage(img);
			position=genrateRandomPos();
		}

		~Food(){
			UnloadTexture(texture);
		}

		void Draw(){
			if (texture.id != 0) {
				DrawTexture(texture, position.x * cellSize, position.y * cellSize, RAYWHITE);
			}
		}

		Vector2 genrateRandomPos(){
			float x = GetRandomValue(0, cellCount-1);
			float y = GetRandomValue(0, cellCount-1);
			return Vector2{x,y};
		}
};


int main(void){
	
	std::cout<<"Let's start!"<<std::endl;
	InitWindow(cellSize*cellCount, cellSize*cellCount, "SnakeySnake");
	SetTargetFPS(60);

	
	{
		Food mincare=Food();
		while(!WindowShouldClose()){
			BeginDrawing();

			ClearBackground(BACKGROUND);
			// DrawText("Let's start!", 290, 300, 30, UI);

			
			mincare.Draw();
			
			EndDrawing();
		}
	}
	

	CloseWindow();
	return 0;
}
