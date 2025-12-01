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
