#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "textureManager.h"
#include "gameObject.h"
#include "gameState.h"

#include <vector>

class GameEngine
{
    public:
        GameEngine();
        void run();
        void close();

    private:
        bool m_running;
        std::vector<GameState*> m_g_states;
};
#endif // GAMEENGINE_H
