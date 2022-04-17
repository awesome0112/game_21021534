#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Math.hpp"
#include "Entity.hpp"
#include "Obstacle.hpp"

using namespace std;

class Tank : public Entity
{
public:
    Tank(Vector2f p_pos, SDL_Texture* p_tex);

    Vector2f& getPos()
    {
        return pos;
    }

    Vector2f& getSpeed()
    {
        return speed;
    }

    SDL_Texture* getTex()
    {
        return TankTex;
    }

    void setPos(float x, float y);
    void setSpeed(float x, float y);

    void Move();
    void handleEvent(SDL_Event& e);
    void handleSpecialEvent(SDL_Event& e, double& degrees, vector<Obstacle> obs);

    bool isCollide(Obstacle obs);
    bool checkMove(vector<Obstacle> obs);

private:
    Vector2f speed;
    Vector2f pos;

    SDL_Texture* TankTex;
};

