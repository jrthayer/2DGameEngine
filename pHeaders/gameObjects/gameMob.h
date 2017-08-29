#ifndef GAMEMOB_H
#define GAMEMOB_H

#include "gameObject.h"

#include <string>

class GameMob : public GameObject
{
    public:
        GameMob(double x, double y, std::string name, double w, double h,
            int r, int c);
        void draw(TextureManager &t_manager);

    private:

        int m_row, m_col;

};

#endif // GAMEMOB_H
