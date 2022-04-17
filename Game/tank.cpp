#include "INCLUDE/Tank.hpp"
#include "INCLUDE/Math.hpp"
#include "INCLUDE/Entity.hpp"
#include "INCLUDE/Obstacle.hpp"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

using namespace std;

Tank::Tank(Vector2f p_pos, SDL_Texture* p_tex)
:Entity(p_pos, p_tex), pos(p_pos), TankTex(p_tex)
{
}

void Tank::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

void Tank::setSpeed(float x, float y)
{
    speed.x = x;
    speed.y = y;
}

/*
void Tank::specialTankRender(Vector2f Pos, SDL_Rect* clip, float angle, SDL_Point* center, SDL_RendererFlip flip);
{
    SDL_Rect renderQuad = {Pos.x , Pos.y, 80, 80};

    if(clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

}
*/

void Tank::handleEvent(SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: speed.y -= 0.1; break;
            case SDLK_s: speed.y += 0.1; break;
            case SDLK_a: speed.x -= 0.1; break;
            case SDLK_d: speed.x += 0.1; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: speed.y += 0.1; break;
            case SDLK_s: speed.y -= 0.1; break;
            case SDLK_a: speed.x += 0.1; break;
            case SDLK_d: speed.x -= 0.1; break;
        }
    }
}

void Tank::Move()
{
    pos.x += speed.x;

    //If the dot went too far to the left or right
    if( ( pos.x < 0 ) || ( pos.x + 80 > 1280 ) )
    {
        //Move back
        pos.x -= speed.x;
    }

    //Move the dot up or down
    pos.y += speed.y;

    //If the dot went too far up or down
    if( ( pos.y < 0 ) || ( pos.y + 80 > 720 ) )
    {
        //Move back
        pos.y -= speed.y;
    }
}

bool Tank::isCollide(Obstacle obs)
{
    return
    (
        (pos.y + 80 <= obs.getPos().y) ||
        (pos.y >= obs.getPos().y + 90) ||
        (pos.x + 80 <= obs.getPos().x) ||
        (pos.x >= obs.getPos().x + 90)
    );
}

bool Tank::checkMove(vector<Obstacle> obs)
{
    for(int i = 0; i < obs.size(); i++)
    {
        if(!isCollide(obs[i])) return false;
    }
    return true;
}

void Tank::handleSpecialEvent(SDL_Event& e, double& degrees, vector<Obstacle> obs)
{
    if(e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
        case SDLK_a:
            degrees = -90;
            if(degrees == -90)
            {
                pos.x -= 5;
                if(pos.x < 0)
                {
                    pos.x += 5;
                }
                if(!checkMove(obs))
                {
                    pos.x +=5;
                }
            }
            break;

        case SDLK_d:
            degrees = 90;
            if(degrees == 90)
            {
                pos.x += 5;
                if(pos.x + 80 > 1280)
                {
                    pos.x -= 5;
                }
                if(!checkMove(obs))
                {
                    pos.x -= 5;
                }
            }
            break;

        case SDLK_w:
            degrees = 0;
            if(degrees == 0)
            {
                pos.y -= 5;
                if(pos.y < 0)
                {
                    pos.y += 5;
                }
                if(!checkMove(obs))
                {
                    pos.y += 5;
                }
            }
            break;

        case SDLK_s:
            degrees = 180;
            if(degrees == 180)
            {
                pos.y += 5;
                if(pos.y + 80 > 720)
                {
                    pos.y -= 5;
                }
                if(!checkMove(obs))
                {
                    pos.y -= 5;
                }
            }
            break;
        }
    }
}
