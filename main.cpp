#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>

Color BACKGROUND={ 12, 35, 20, 255 };
Color UI = { 220, 240, 255, 255 };
Color SNAKE = { 50, 205, 95, 255 };

int cellSize=30;
int cellCount=25;
int offset=75;

double lastUpdateTime=0;

enum class GameState{
	MENU,
	GAMEPLAY
};

bool EventTriggered(double interval){
	double currentTime=GetTime();
	if(currentTime-lastUpdateTime>=interval){
		lastUpdateTime=currentTime;
		return true;
	}
	return false;
}

bool ElementInDeque(Vector2 element, std::deque<Vector2> deq){
	for(int i=0; i<deq.size(); i++){
		if(Vector2Equals(deq[i], element))
			return true;
	}
	return false;
}

class Food{

	public:
		Vector2 position;
		Texture2D texture;

		Food(std::deque<Vector2> snakeBody){
			Image img=LoadImage("graphics/mar.png");
			ImageResize(&img, cellSize, cellSize);
			texture=LoadTextureFromImage(img);
			UnloadImage(img);
			position=genrateRandomPos(snakeBody);
		}

		~Food(){
			UnloadTexture(texture);
		}

		void Draw(){
			if (texture.id != 0) {
				DrawTexture(texture, offset+1 + position.x * cellSize, offset +1+ position.y * cellSize, RAYWHITE);
			}
		}

		Vector2 generateRandomCell(){
			float x = GetRandomValue(0, cellCount-1);
			float y = GetRandomValue(0, cellCount-1);
			return Vector2{x,y};
		}

		Vector2 genrateRandomPos(std::deque<Vector2> snakeBody){
			Vector2 position=generateRandomCell();
			while(ElementInDeque(position, snakeBody))
			{
				position=generateRandomCell();
			}
			return position;
		}
};

class Snake{

	public:
		std::deque<Vector2> body = {Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
		Vector2 direction=Vector2{1,0};
		bool addSeg=false;

		void Draw(){
			for(int i=0; i<body.size(); i++){
				Rectangle bucata = Rectangle{body[i].x * cellSize +offset, body[i].y * cellSize+offset, (float)cellSize, (float)cellSize};
				DrawRectangleRounded(bucata, 0.5, body.size(), SNAKE);
			}
		}

		void updatePos(){
			if(addSeg){
				addSeg=false;
			}else{
				body.pop_back();
			}
			body.push_front(Vector2Add(body[0], direction));
		}

		void Reset(){
			body={Vector2{6,9}, Vector2{5,9}, Vector2{4,9}};
		}
};

class Game{
	public:
		Snake snake=Snake();
		Food food=Food(snake.body);
		bool running=true;
		int score=0;
		int high_score=0;

		void Draw(){
			food.Draw();
			snake.Draw();
			if(!running){
				DrawText("GAME OVER:(", 550, offset+cellSize*cellCount+10 ,40 , SNAKE);

			}
		}

		void Update(){
			if(running){
				snake.updatePos();
				CheckCollisionWithFood();
				CheckCollisionWithEdges();
				CheckCollisionWithTail();
				CheckHighScore();
			}
		}

		

		void CheckCollisionWithFood(){
			if(Vector2Equals(snake.body[0], food.position)){
				food.position=food.genrateRandomPos(snake.body);
				snake.addSeg=true;
				score++;
			}
		}

		void CheckCollisionWithEdges(){
			if(snake.body[0].x==cellCount || snake.body[0].x==-1){
				GameOver();
			}
			if(snake.body[0].y==cellCount || snake.body[0].y==-1){
				GameOver();
			}
		}

		void CheckCollisionWithTail(){
			std::deque<Vector2> headless=snake.body;
			headless.pop_front();
			for(int i=0; i<headless.size(); i++)
			{
				if(headless[i]==snake.body[0])
					GameOver();
			}
		}

		void CheckHighScore(){
			if(high_score<score)
				high_score=score;
		}

		void GameOver(){
			snake.Reset();
			food.position=food.genrateRandomPos(snake.body);
			running=false;
			score=0;
			// DrawText("GAME OVER:(", offset-5, offset+cellSize*cellCount+10 ,40 , SNAKE);
		}
};

void menu(int window_width, Rectangle startButton, bool hoverStart)
{
	const char* title = "LET'S PLAY!";
				int fontSize = 40;
				int titleWidth = MeasureText(title, fontSize);
				DrawText(title,
						window_width/2 - titleWidth/2,
						window_width/2 - 100,
						fontSize,
						(Color){220, 240, 255, 255}); 

				Color buttonColor = hoverStart
					? (Color){80, 170, 255, 255}  
					: (Color){30, 60, 110, 255};  

				DrawRectangleRec(startButton, buttonColor);
				const char* btnText = "START";
				int btnFontSize = 20;
				int textW = MeasureText(btnText, btnFontSize);
				DrawText(btnText,
						startButton.x + startButton.width/2 - textW/2,
						startButton.y + startButton.height/2 - btnFontSize/2,
						btnFontSize,
						RAYWHITE);
}


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
