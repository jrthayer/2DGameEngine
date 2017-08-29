#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "textureManager.h"
#include "inputManager.h"

#include <string>
#include <vector>

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
        void update(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i_manager);
        void setUpdate(bool(*func)(GameObject&, std::vector<GameObject*>&, InputManager&));

        //getters
        int getX(){return m_x;};
        int getY(){return m_y;};
        std::string getName(){return m_name;};
        int getStat(int index){return m_stats[index];};

        //setters
        void setX(int x){m_x = x;};
        void setY(int y){m_y = y;};
        void setStat(int index, int value){m_stats[index] = value;};

    protected:
        GameObject(int x, int y, std::string name);
        bool(*m_update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager) = NULL;

        int m_x, m_y;
        std::string m_name;
        int m_stats[5] = {};
};
#endif // GAMEOBJECT_H
