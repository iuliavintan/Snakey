#include "defines.hpp"

Color BACKGROUND = {12, 35, 20, 255};
Color UI = {220, 240, 255, 255};
Color SNAKE = {50, 205, 95, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, std::deque<Vector2> deq) {
    for (int i = 0; i < deq.size(); i++) {
        if (Vector2Equals(deq[i], element))
            return true;
    }
    return false;
}

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
