#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

extern Color BACKGROUND;
extern Color UI;
extern Color SNAKE;

extern int cellSize;
extern int cellCount;
extern int offset;

extern double lastUpdateTime;

enum class GameState {
    MENU,
    GAMEPLAY
};

bool EventTriggered(double interval);

bool ElementInDeque(Vector2 element, std::deque<Vector2> deq);

#endif
