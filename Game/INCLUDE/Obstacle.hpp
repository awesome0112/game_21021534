#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"
#include "Entity.hpp"

using namespace std;

class Obstacle : public Entity
{
public:
    Obstacle(Vector2f p_pos, SDL_Texture* p_tex);

    SDL_Texture* getTex()
    {
        return ObsTex;
    }

    Vector2f& getPos()
    {
        return pos;
    }

    void setPos(float x, float y);

private:
    Vector2f pos;

    SDL_Texture* ObsTex;
};
