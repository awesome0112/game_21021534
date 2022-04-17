#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    //SDL_Surface* loadSurface(const char* p_filePath);

    SDL_Window* getWindow();

    int getRefreshRate();

    void cleanUp();
    void Clear();
    void display();

    void render(Entity& p_entity);
    void renderTank(Vector2f p_pos , SDL_Texture* p_tex);
    void renderSpecialTank(Vector2f p_pos, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Texture* p_tex);

    //SDL_Surface* getWindowSurface();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    //SDL_Surface* windowSurface;
};
