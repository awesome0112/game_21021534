#include "INCLUDE/Obstacle.hpp"
#include "INCLUDE/Math.hpp"
#include "INCLUDE/Entity.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

Obstacle::Obstacle(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex), pos(p_pos), ObsTex(p_tex)
{
}

void Obstacle::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}
