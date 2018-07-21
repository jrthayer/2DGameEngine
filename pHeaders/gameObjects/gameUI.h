#ifndef GAMEUI_H
#define GAMEUI_H

#include "gameObject.h"

#include <SDL.h>
#include <SDL_ttf.h>


#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <cstring>

class GameUI : public GameObject
{
    public:
        GameUI(double x, double y, std::string name, SDL_Color color, int size,
            std::string text, std::string font_loc);
        void draw(TextureManager &t_manager);

        //setters
        void setText(const char* text){m_text = text;};

    private:
        int m_size;
        std::string m_font_loc;
        SDL_Color m_color;
        const char* m_text;
};

#endif // GAMEUI_H
