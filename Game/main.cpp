
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "INCLUDE/renderwindow.hpp"
#include "INCLUDE/Entity.hpp"
#include "INCLUDE/Utils.hpp"
#include "INCLUDE/Tank.hpp"
#include "INCLUDE/Obstacle.hpp"

using namespace std;

const int WIDTH = 1280;
const int HEIGHT = 720;
const float TANK_SIZE = 80;
const float WALL_SIZE = 90;
const float SPEED = 10;

bool GameIsRunning = true;

SDL_Event e;

int main(int argc, char* args[])
{
    if(SDL_Init (SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_INIT failed! Error: " << SDL_GetError() << endl;
    }

    if(!IMG_Init (IMG_INIT_PNG))
    {
        cout << "IMG_INIT failed! Error: " << SDL_GetError() << endl;
    }

    RenderWindow window("M.Quan", WIDTH, HEIGHT);

    //cout << window.getRefreshRate() << endl;

    SDL_Texture* tankV1 = window.loadTexture("PNG/tankV1.png");
    SDL_Texture* tankV2 = window.loadTexture("PNG/tankV2.png");
    SDL_Texture* tankV3 = window.loadTexture("PNG/tankV3.png");
    SDL_Texture* tankV4 = window.loadTexture("PNG/tankV4.png");
    SDL_Texture* tankV5 = window.loadTexture("PNG/tankV5.png");
    SDL_Texture* tankV6 = window.loadTexture("PNG/tankV6.png");
    SDL_Texture* ufo = window.loadTexture("PNG/ufo.png");
    SDL_Texture* backgroundTexture = window.loadTexture("PNG/background.png");
    SDL_Texture* brickWall = window.loadTexture("PNG/brick_wall.png");
    SDL_Texture* ironWallV1 = window.loadTexture("PNG/iron_wallV1.png");
    SDL_Texture* ironWallV2 = window.loadTexture("PNG/iron_wallV2.png");
    SDL_Texture* grass = window.loadTexture("PNG/grass.png");

    Tank myTank(Vector2f(0, 0), tankV6);
    myTank.setSpeed(0, 0);

    vector<Obstacle> obstacles;
    obstacles.push_back(Obstacle(Vector2f(0, WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE, WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3 + 80, WALL_SIZE*2 - 40), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3 + 60, 230 - 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3, 230 - 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - 2*WALL_SIZE, WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE, WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4 - 80, WALL_SIZE*2 - 40), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4 - 60, 230 - 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4, 230 - 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, TANK_SIZE + 1), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, TANK_SIZE + 1), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, 110), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, 110), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, WALL_SIZE + 110), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, WALL_SIZE + 110), brickWall));
    obstacles.push_back(Obstacle(Vector2f(0, HEIGHT/2), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE, HEIGHT/2 - WALL_SIZE), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE, HEIGHT/2), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(0, HEIGHT/2 - WALL_SIZE), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(0, HEIGHT - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE, HEIGHT - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE, HEIGHT - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*2, HEIGHT - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, HEIGHT - TANK_SIZE - WALL_SIZE - 1), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, HEIGHT - 110 - WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2 - WALL_SIZE, HEIGHT - 110 - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, HEIGHT - TANK_SIZE - WALL_SIZE - 1), ironWallV2));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, HEIGHT - 110 - WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH/2, HEIGHT - 110 - WALL_SIZE*2), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3 + 80, HEIGHT - (WALL_SIZE*2 - 40) - WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3 + 60, HEIGHT - WALL_SIZE - 230 + 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WALL_SIZE*3, HEIGHT - WALL_SIZE - 230 + 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4 - 80, HEIGHT - (WALL_SIZE*2 - 40) - WALL_SIZE), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4 - 60, HEIGHT - WALL_SIZE - 230 + 10), brickWall));
    obstacles.push_back(Obstacle(Vector2f(WIDTH - WALL_SIZE*4, HEIGHT - WALL_SIZE - 230 + 10), brickWall));

    //int x = 0, y = 200;
    //Entity backgound(Vector2f(x, y), backgroundPic);

    //const float timeStep= 0.01f;
    //float accumulator = 0.0f;
    //float currentTime = utils::hireTimeInSeconds();

    double degrees = 0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    while(GameIsRunning)
    {

        //int startTicks = SDL_GetTicks();

        //float newTime = utils::hireTimeInSeconds();
        //float frameTime = newTime - currentTime;

        //currentTime = newTime;

        //accumulator += frameTime;

        //while(accumulator >= timeStep)
        //{
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                GameIsRunning = false;
            }
                /*
                else if(event.type == SDL_KEYDOWN)
                {
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_a:
                        myTank.setPos(myTank.getPos().x-=5, myTank.getPos().y);
                        break;
                    case SDLK_d:
                        myTank.setPos(myTank.getPos().x+=5, myTank.getPos().y);
                        break;
                    case SDLK_w:
                        myTank.setPos(myTank.getPos().x, myTank.getPos().y-=5);
                        break;
                    case SDLK_s:
                        myTank.setPos(myTank.getPos().x, myTank.getPos().y+=5);
                        break;
                    }
                }
                */
                //myTank.handleEvent(e);
            myTank.handleSpecialEvent(e, degrees, obstacles);
        }
/*
        for(int i = 0; i < obstacles.size(); i++)
        {

            if(myTank.getPos().x + TANK_SIZE > obstacles[i].getPos().x && myTank.getPos().y < obstacles[i].getPos().y + WALL_SIZE && myTank.getPos().x < obstacles[i].getPos().x + WALL_SIZE && myTank.getPos().y + TANK_SIZE > obstacles[i].getPos().y)
            {
                    myTank.setPos(myTank.getPos().x - 5, myTank.getPos().y);
            }
            if(myTank.getPos().x + TANK_SIZE > obstacles[i].getPos().x && myTank.getPos().y < obstacles[i].getPos().y + WALL_SIZE && myTank.getPos().y + TANK_SIZE > obstacles[i].getPos().y && myTank.getPos().x < obstacles[i].getPos().x + WALL_SIZE)
            {
                    myTank.setPos(myTank.getPos().x, myTank.getPos().y + 5);
            }

            if(myTank.getPos().x < obstacles[i].getPos().x + WALL_SIZE && myTank.getPos().y + TANK_SIZE > obstacles[i].getPos().y && myTank.getPos().x + TANK_SIZE > obstacles[i].getPos().x && myTank.getPos().y < obstacles[i].getPos().y + WALL_SIZE)
            {
                    myTank.setPos(myTank.getPos().x + 5, myTank.getPos().y);
            }
            if(myTank.getPos().x + TANK_SIZE > obstacles[i].getPos().x && myTank.getPos().y + TANK_SIZE > obstacles[i].getPos().y && myTank.getPos().y < obstacles[i].getPos().y + WALL_SIZE && myTank.getPos().x < obstacles[i].getPos().x + WALL_SIZE)
            {
                    myTank.setPos(myTank.getPos().x, myTank.getPos().y - 5);
            }
        }
        */
            //accumulator -= timeStep;
        //}

        //const float alpha = accumulator / timeStep;

        window.Clear();

        //myTank.Move();

        //window.render(backgound);

        window.renderTank(Vector2f(0, 0), backgroundTexture);

        for(int i = 0; i < obstacles.size(); i++)
        {
            window.renderTank(obstacles[i].getPos(), obstacles[i].getTex());
        }

        window.renderSpecialTank(myTank.getPos(), NULL, degrees, NULL, flipType, myTank.getTex());

        window.display();

        //int frameTicks = SDL_GetTicks() - startTicks;

        //if(frameTicks < 1000 / window.getRefreshRate()) SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
