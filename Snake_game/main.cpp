#include <iostream>
#include <SDL2/SDL.h>

#include "Snake.h"
#include "Food.h"

using namespace std;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Snaek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int currentTime = 0;
    int prevTime = 0;
    float delta = 0.0f;

    SDL_Event ev;
    bool isRunning = true;

    Snake snake;
    Food food;
    food.Move();

    while(isRunning) {

        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        delta = (currentTime - prevTime) / 1000.0f;
        //cout << delta << endl;

        while(SDL_PollEvent(&ev)) {
            if(ev.type == SDL_QUIT) {
                isRunning = false;
            } else if(ev.type == SDL_KEYDOWN) {
                switch(ev.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;

                case SDLK_w:
                    cout << "W" << endl;
                    if(snake.vy != 1) {
                        snake.vx = 0;
                        snake.vy = -1;
                    }
                    break;

                case SDLK_s:
                    cout << "S" << endl;
                    if(snake.vy != -1) {
                        snake.vx = 0;
                        snake.vy = 1;
                    }
                    break;

                case SDLK_a:
                    cout << "A" << endl;
                    if(snake.vx != 1) {
                        snake.vx = -1;
                        snake.vy = 0;
                    }
                    break;

                case SDLK_d:
                    cout << "D" << endl;
                    if(snake.vx != -1) {
                        snake.vx = 1;
                        snake.vy = 0;
                    }
                    break;
                }
            }
        }

        snake.Update(delta, food);

        SDL_SetRenderDrawColor(renderTarget, 0, 0, 0, 255);
        SDL_RenderClear(renderTarget);

        snake.Draw(renderTarget);
        food.Draw(renderTarget);

        SDL_RenderPresent(renderTarget);
    }


    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_DestroyRenderer(renderTarget);
    renderTarget = nullptr;

    SDL_Quit();

    return 0;
}
