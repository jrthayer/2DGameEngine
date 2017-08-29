#include "gameEngine.h"
#include "gameObject.h"
#include "gameMob.h"
#include "gameUI.h"

#include <vector>
#include <string>

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

    GameUI* test = new GameUI(0, 0, {255,0,0}, 50, "assets/test.ttf", "jellp");
    GameMob* yep = new GameMob(100, 100, 100, 100, 0, 0, "error");

    GameEngine game;
    game.addGameObject(test);
    game.addGameObject(yep);
    game.run();
    game.winCondition(func);
    return 0;
}
