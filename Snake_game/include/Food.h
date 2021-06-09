#ifndef FOOD_H
#define FOOD_H

#include <SDL2/SDL.h>

class Food
{
    private:

    public:
        int x, y;

        Food();
        virtual ~Food();

        void Move();
        void Draw(SDL_Renderer* renderTarget);
};

#endif // FOOD_H
