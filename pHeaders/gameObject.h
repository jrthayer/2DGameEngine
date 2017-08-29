#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "textureManager.h"
#include "inputManager.h"

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
        virtual void draw(TextureManager &t_manager) = 0;
        void update(GameObject *g, InputManager &i_manager);
        void setUpdate(void(*func)(const GameObject&, InputManager &i_manager));

    protected:
        GameObject(int x, int y);
        void(*m_update)(const GameObject&, InputManager &i_manager) = NULL;

        //m_w = width, m_h = height
        int m_x, m_y;
};
#endif // GAMEOBJECT_H
