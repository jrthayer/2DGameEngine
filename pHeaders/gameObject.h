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
        double getX(){return m_x;};
        double getY(){return m_y;};
        double getWidth(){return m_w;};
        double getHeight(){return m_h;};
        std::string getName(){return m_name;};
        double getStat(int index){return m_stats[index];};


        //setters
        void setX(double x){m_x = x;};
        void setY(double y){m_y = y;};
        void setStat(int index, double value){m_stats[index] = value;};

    protected:
        GameObject(double x, double y, double w, double h, std::string name);
        bool(*m_update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager) = NULL;

        //m_w = width, m_h = height
        double m_x, m_y, m_w, m_h;
        std::string m_name;
        double m_stats[5] = {};
};
#endif // GAMEOBJECT_H
