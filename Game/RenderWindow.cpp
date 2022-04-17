#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "INCLUDE/renderwindow.hpp"
#include "INCLUDE/Entity.hpp"

using namespace std;

RenderWindow::RenderWindow(const char* title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL)
    {
        cout << "Window failed to init! Error: " << SDL_GetError() << endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL)
    {
        cout << "failed to load texture! Error: " << SDL_GetError() << endl;
    }
    return texture;
}
/*
SDL_Surface* RenderWindow::loadSurface(const char* p_filePath)
{
    SDL_Surface* testSurface = SDL_GetWindowSurface( window );
    SDL_Surface* surface = NULL;

    SDL_Surface* loadedSurface = IMG_Load(p_filePath);
    if(loadedSurface == NULL)
    {
        cout << "failed to load image! error: " << SDL_GetError();
    }
    else
    {
        surface = SDL_ConvertSurface(loadedSurface, testSurface->format, 0);
        if(surface == NULL)
        {
            cout << "failed to optimize image! error: " << SDL_GetError();
        }
        SDL_FreeSurface(testSurface);
        SDL_FreeSurface(loadedSurface);
    }
    return surface;
}
*/
int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex( window );

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::renderTank(Vector2f p_pos, SDL_Texture* p_tex)
{
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w;
	src.h;

	SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = p_pos.x;
	dst.y = p_pos.y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::renderSpecialTank(Vector2f p_pos, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Texture* p_tex)
{
    SDL_Rect renderQuad = {p_pos.x, p_pos.y, 80, 80};

    if(clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(renderer, p_tex, clip, &renderQuad, angle, center, flip);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getPos().x * 1;
    dst.y = p_entity.getPos().y * 1;
    dst.w = p_entity.getCurrentFrame().w * 1 ;
    dst.h = p_entity.getCurrentFrame().h * 1 ;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Window* RenderWindow::getWindow()
{
    return window;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

