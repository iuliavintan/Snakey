#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>

Color BACKGROUND={10, 20, 40, 255};
Color UI = { 220, 240, 255, 255 };
Color SNAKE = { 80, 170, 255, 255 };

int cellSize=30;
int cellCount=25;

double lastUpdateTime=0;

bool EventTriggered(double interval){
	double currentTime=GetTime();
	if(currentTime-lastUpdateTime>=interval){
		lastUpdateTime=currentTime;
		return true;
	}
	return false;
}

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

class Snake{

	public:
		std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
		Vector2 direction=Vector2{1,0};

		void Draw(){
			for(int i=0; i<body.size(); i++){
				Rectangle bucata = Rectangle{body[i].x * cellSize, body[i].y * cellSize, (float)cellSize, (float)cellSize};
				DrawRectangleRounded(bucata, 0.5, body.size(), SNAKE);
			}
		}

		void updatePos(){
			body.pop_back();
			body.push_front(Vector2Add(body[0], direction));
		}

};

class Game{
	public:
		Snake snake=Snake();
		Food food=Food();

		void Draw(){
			food.Draw();
			snake.Draw();
		}

		void Update(){
			snake.updatePos();
		}
};

int main(void){
	
	std::cout<<"Let's start!"<<std::endl;
	InitWindow(cellSize*cellCount, cellSize*cellCount, "SnakeySnake");
	SetTargetFPS(60);

	
	{
		Game game=Game();
		while(!WindowShouldClose()){
			BeginDrawing();

			if(EventTriggered(0.2)){
				game.Update();
			}

			if((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && game.snake.direction.y!=1){
				game.snake.direction={0,-1};	
			}else if((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && game.snake.direction.y!=-1){
				game.snake.direction={0,1};
			}else if((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && game.snake.direction.x!=1){
				game.snake.direction={-1,0};
			}else if((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && game.snake.direction.x!=-1){
				game.snake.direction={1,0};
			}

			ClearBackground(BACKGROUND);
			game.Draw();
			EndDrawing();
		}
	}
	

	CloseWindow();
	return 0;
}
