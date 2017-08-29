#ifndef GAMEMOB_H
#define GAMEMOB_H

#include "gameObject.h"

#include <string>

class GameMob : public GameObject
{
    public:
        GameMob(int x, int y, std::string name, int w, int h, int r, int c,
            std::string id);
        void draw(TextureManager &t_manager);

    private:
        //m_w = width, m_h = height
        int m_w, m_h, m_row, m_col;
        std::string m_id;
};

#endif // GAMEMOB_H
