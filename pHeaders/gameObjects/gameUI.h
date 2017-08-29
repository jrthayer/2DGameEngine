#ifndef GAMEUI_H
#define GAMEUI_H

#include "gameObject.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>

class GameUI : public GameObject
{
    public:
        GameUI(double x, double y, std::string name, SDL_Color color, int size,
            char* text, std::string font_loc);
        void draw(TextureManager &t_manager);

    private:
        int m_size;
        std::string m_font_loc;
        SDL_Color m_color;
        char* m_text;
};

#endif // GAMEUI_H