#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameObject.h"
#include "textureManager.h"

#include <vector>

/*
DESCRIPTION
    The GameState is responsible for containing all the GameObjects
    that make up a specific screen, calling draw on those
    GameObjects, calling update on those GameObjects, determining
    when this GameState is complete, and which GameState is next
===================================================================
*/
class GameState
{
    public:
        GameState();
        void addObject(GameObject *g_object);
        void draw(TextureManager &t_manager);
        void update();
        void setNextState(GameState* next);
        GameState* getNextState();
    private:
        std::vector<GameObject*> m_g_objects;
        GameState* m_next_state;

};
#endif // GAMESTATE_H
