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

//    std::cout << "X:" << x << std::endl;
//    std::cout << "Y:" << y << std::endl;
    std::cout << "length:" << tail_len << std::endl;
    std::cout << "start:" << tail_start << std::endl;
    std::cout << "end:" << tail_end << std::endl;

    frameCounter += delta;

    if(frameCounter >= 0.10f) {
        frameCounter = 0;

        tail[tail_end % 255].x = x;
        tail[tail_end % 255].y = y;

        tail_start++;
        tail_end++;

        //move snek
        x += vx;
        y += vy;

        //if hit edge go to other side
        x = (x + 50) % 50;
        y = (y + 50) % 50;

        //eat food
        if(x == food.x && y == food.y) {
            tail_len++;
            tail_start--;
            food.Move();
        }

        //hit tail
        for (int i = 0; i < tail_len; i++) {
            Tail& tail_pos = tail[(tail_start + i) % 255];
            if (tail_pos.x == x && tail_pos.y == y) {
                //we ded
                tail_len = 0;
                tail_start = tail_end;
            }
        }
    }
}

void Snake::Draw(SDL_Renderer* renderTarget) {
    SDL_SetRenderDrawColor(renderTarget, 0, 255, 0, 255);

    snakeHead.x = 16*x;
    snakeHead.y = 16*y;
    snakeHead.w = 16;
    snakeHead.h = 16;

    SDL_RenderFillRect(renderTarget, &snakeHead);

    for (int i = 0; i < tail_len; i++) {
        Tail& tail_pos = tail[(tail_start + i) % 255];
        SDL_Rect r{ 16 * tail_pos.x, 16 * tail_pos.y, 16, 16 };
        SDL_RenderFillRect(renderTarget, &r);
    }
}
