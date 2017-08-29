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
        void draw(TextureManager t_mangaer);
        void addGameObject(GameObject* g_object);
        bool winCondition(bool(*func)(std::vector<GameObject*>*));

    private:
        bool m_running;
        std::vector<GameObject*> m_g_objects;
};
#endif // GAMEENGINE_H
