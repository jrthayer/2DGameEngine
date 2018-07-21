#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "textureManager.h"
#include "inputManager.h"
#include "gameObject.h"
#include "gameMob.h"
#include "gameUI.h"
#include "collision.h"

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
        void loadTexture(std::string id, const char* file);
        bool winCondition(bool(*func)(std::vector<GameObject*>*));

    private:
        bool m_running;
        std::vector<GameObject*> m_g_objects;
        TextureManager m_t_manager;
        InputManager m_i_manager;
};
#endif // GAMEENGINE_H
