#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.hpp"

class Entity
{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex);
    //Entity(Vector2f p_pos, SDL_Surface* p_sur);
    Vector2f& getPos()
    {
        return pos;
    }
/*
    Vector2f& getSize()
    {
        return Size;
    }
*/
    SDL_Texture* getTex();
    //SDL_Surface* getSur();
    SDL_Rect getCurrentFrame();
private:
    Vector2f pos;
    //Vector2f Size;

    SDL_Rect currentFrame;
    SDL_Texture* tex;
    //SDL_Surface* sur;
};
