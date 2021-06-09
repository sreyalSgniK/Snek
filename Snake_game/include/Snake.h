#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>

#include "Food.h"

class Snake
{
private:
    int x, y;
    SDL_Rect snakeHead;
    bool isActive;
    float frameCounter;
public:
    int vx = 0, vy = 0;

    Snake();
    virtual ~Snake();

    void Update(float delta, Food& food);
    void Draw(SDL_Renderer* renderTarget);
};

#endif // SNAKE_H
