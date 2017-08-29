#include "gameEngine.h"
#include "gameObject.h"

#include <vector>

bool win(std::vector<GameObject*> *g_objects)
{
    std::vector<GameObject*>::iterator iter;

    for(iter = g_objects->begin(); iter < g_objects->end(); iter++)
    {

    }
    return true;
}

int main(int argc, char* argv[])
{
    bool(*func)(std::vector<GameObject*>*);
    func = &win;

    GameEngine game;
    game.run();
    game.winCondition(func);
    return 0;
}
