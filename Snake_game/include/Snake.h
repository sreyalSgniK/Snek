#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>

#include "Food.h"

struct Tail{
    int x, y;
};

class Snake
{
private:
    int x = 0, y = 0;
    SDL_Rect snakeHead;

    bool isActive;
    float frameCounter = 0;

    Tail tail[255];
    int tail_len = 0;
    int tail_start = 0, tail_end = 0;
public:
    int vx = 0, vy = 0;

    Snake();
    virtual ~Snake();

    void Update(float delta, Food& food);
    void Draw(SDL_Renderer* renderTarget);
};

#endif // SNAKE_H
