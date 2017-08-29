#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "textureManager.h"
#include "gameObject.h"

#include <vector>

class GameEngine
{
    public:
        GameEngine();
        void run();
        void close();
        void update();
        void draw();
        void addGameObject();

    private:
        bool m_running;
        std::vector<GameObject*> m_g_objects;
};
#endif // GAMEENGINE_H
