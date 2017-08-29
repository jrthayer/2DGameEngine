#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>
#include <map>
#include <iostream>

/*
DESCRIPTION
    The TextureManager is responsible for displaying all the visuals
    of the game including: window creation, loading game textures,
    and drawing game textures
===================================================================
*/
class TextureManager
{
    public:
        TextureManager();
        void load(std::string id, const char *filename);
        void draw(int x, int y, int w, int h, int row, int col,
                  std::string id, SDL_RendererFlip flip);
        void render();
        /*
        void drawText(int x_loc, int y_loc, SDL_Color color, TTF_Font* font,
                      char* text);
        */
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        std::map<std::string, SDL_Texture*> m_game_textures;
};
#endif // TEXTUREMANAGER_H
