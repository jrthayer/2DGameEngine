#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "textureManager.h"
#include "gameObject.h"

class GameEngine
{
    public:
        GameEngine();
        void run();
        void close();

    private:
        bool m_running;
};
#endif // GAMEENGINE_H
