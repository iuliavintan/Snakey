// #include<iostream>
// #include<raylib.h>
// #include<deque>
// #include<raymath.h>

// class Food{

// 	public:
// 		Vector2 position;
// 		Texture2D texture;

// 		Food(std::deque<Vector2> snakeBody){
// 			Image img=LoadImage("graphics/mar.png");
// 			ImageResize(&img, cellSize, cellSize);
// 			texture=LoadTextureFromImage(img);
// 			UnloadImage(img);
// 			position=genrateRandomPos(snakeBody);
// 		}

// 		~Food(){
// 			UnloadTexture(texture);
// 		}

// 		void Draw(){
// 			if (texture.id != 0) {
// 				DrawTexture(texture, offset+1 + position.x * cellSize, offset +1+ position.y * cellSize, RAYWHITE);
// 			}
// 		}

// 		Vector2 generateRandomCell(){
// 			float x = GetRandomValue(0, cellCount-1);
// 			float y = GetRandomValue(0, cellCount-1);
// 			return Vector2{x,y};
// 		}

// 		Vector2 genrateRandomPos(std::deque<Vector2> snakeBody){
// 			Vector2 position=generateRandomCell();
// 			while(ElementInDeque(position, snakeBody))
// 			{
// 				position=generateRandomCell();
// 			}
// 			return position;
// 		}
// };
