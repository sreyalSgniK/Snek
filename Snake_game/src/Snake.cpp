#include <iostream>
#include <iomanip>

#include "Snake.h"
#include "Food.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

void Snake::Update(float delta, Food& food) {

    std::cout << "X:" << x << std::endl;
    std::cout << "Y:" << y << std::endl;

    frameCounter += delta;

    if(frameCounter >= 0.10f) {
        frameCounter = 0;
        x += vx;
        y += vy;

        if(x == food.x && y == food.y) {
            food.Move();
        }
    }
}

void Snake::Draw(SDL_Renderer* renderTarget) {
    snakeHead.x = 16*x;
    snakeHead.y = 16*y;
    snakeHead.w = 16;
    snakeHead.h = 16;
    SDL_SetRenderDrawColor(renderTarget, 0, 255, 0, 255);
    SDL_RenderFillRect(renderTarget, &snakeHead);
}
