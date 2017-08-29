#include "textureManager.h"

/*
DESCRIPTION
    Initialize SDL library, create window, and create renderer
===================================================================
*/
TextureManager::TextureManager()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow("title", 50, 50, 1000, 500, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

    if(SDL_GetError() < 0)
    {
        const char* error = SDL_GetError();
        std::cerr<<"SDL setup process Failed: "<<error<<std::endl;
        SDL_ClearError();
    }

    load("error", "textures/textureLoadError.png");
}

/*
DESCRIPTION
    Loads a image from filename provided, converts the image into
    a texture(which SDL can use), and stores the texture in a map
    of textures
===================================================================
INPUTS:
    string id            = name associated with the map of textures
    const char* filename = filename/location of texture being loaded
===================================================================
*/
void TextureManager::load(std::string id, const char* filename)
{
    SDL_Texture* texture = IMG_LoadTexture(m_renderer, filename);

    if(texture != NULL)
        m_game_textures[id] = texture;
    else
        std::cerr<<"TextureManger Load failed to load texture"<<std::endl;
}

/*
DESCRIPTION
    This function draws a texture onto the window
===================================================================
INPUTS:
    string id        = name associated with the texture
    int w            = width of texture
    int h            = height of texture
    int x            = x location of texture inside the window
    int y            = y location of texture inside the window
    int col          = used for portion of texture
    int row          = used for portion of texture
    SDL_RendererFlip = is the image flipped in any direction
===================================================================
*/
void TextureManager::draw(int x, int y, int w, int h, int row, int col,
                          std::string id, SDL_RendererFlip flip)
{
    SDL_Rect src_rect;
    SDL_Rect dest_rect;

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.w = src_rect.w = w;
    dest_rect.h = src_rect.h = h;

    src_rect.x = col*w;
    src_rect.y = h*row;

    SDL_RenderCopyEx(m_renderer, m_game_textures[id], &src_rect, &dest_rect, 0,
                     0, flip);
}


/*
DESCRIPTION
    Displays all textures on the render to the screen and then
    cleans the render
===================================================================
*/
void TextureManager::render()
{
    //draw("error", 50, 50, 100, 100, 0, 0, SDL_FLIP_NONE);
    SDL_RenderPresent(m_renderer);
    SDL_RenderClear(m_renderer);
}
