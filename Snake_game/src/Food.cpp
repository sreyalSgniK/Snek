#include <stdlib.h>
#include <time.h>

#include "Food.h"

Food::Food()
{

}

Food::~Food()
{

}

void Food::Move() {
    srand(time(0));
    x = rand() % 50;
    y = rand() % 50;
}

void Food::Draw(SDL_Renderer* renderTarget) {
    SDL_Rect food{16*x, 16*y, 16, 16};
    SDL_SetRenderDrawColor(renderTarget, 255, 0, 0, 255);
    SDL_RenderFillRect(renderTarget, &food);
}
