#include "gameUI.h"

GameUI::GameUI(int x, int y, SDL_Color color, int size, std::string font_loc,
    char* text) : GameObject(x,y), m_size(size), m_font_loc(font_loc),
    m_color(color), m_text(text)
{

}

/*
DESCRIPTION
    Uses a TextureManager to draw itself to the screen
===================================================================
INPUTS:
    TextureManager &t_manager = pass by reference the TextureManager
                                that will draw the GameObject
===================================================================
NOTE: needs to be pass by reference since we need the game's
      TextureManager to draw the gameObject to the SDL renderer
      connected to the game window
*/
void GameUI::draw(TextureManager &t_manager)
{
    //flip option included for future feature, none by default
    t_manager.drawText(m_x, m_y, m_color, m_size, m_font_loc, m_text);
}


