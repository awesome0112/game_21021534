#include "INCLUDE/Entity.hpp"

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
    SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}
/*
Entity::Entity(Vector2f p_pos, SDL_Surface* p_sur)
:pos(p_pos), sur(p_sur)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}
*/
SDL_Texture* Entity::getTex()
{
    return tex;
}
/*
SDL_Surface* Entity::getSur()
{
    return sur;
}
*/
SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}
