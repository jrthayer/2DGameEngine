#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "textureManager.h"

#include <string>

/*
DESCRIPTION
    The GameObject is responsible for returning and updating its
    own values, as well as using the TextureManager to draw itself
    to the screen
===================================================================
*/
class GameObject
{
    public:
        void draw(TextureManager &t_manager);
        virtual void update() = 0;

    protected:
        GameObject(int x, int y, int w, int h, int r, int f, std::string id);
        //m_w = width, m_h = height
        int m_x, m_y, m_w, m_h, m_row, m_col;
        std::string m_id;
};

#endif // GAMEOBJECT_H
