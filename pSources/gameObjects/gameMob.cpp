#include "gameMob.h"

GameMob::GameMob(int x, int y, int w, int h, int r, int c,
    std::string id) : GameObject(x,y), m_w(w), m_h(h),
    m_row(r), m_col(c), m_id(id)
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
void GameMob::draw(TextureManager &t_manager)
{
    //flip option included for future feature, none by default
    t_manager.draw(m_x, m_y, m_w, m_h, m_row, m_col, m_id, SDL_FLIP_NONE);
}

