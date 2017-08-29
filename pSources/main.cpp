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

void test()
{
    std::cout<<"HelloWorld"<<std::endl;
}

bool player1Update(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    if(i.isKeyDown(SDL_SCANCODE_W)&&g1.getY() > 0)
        g1.setY(g1.getY()-1);
    if(i.isKeyDown(SDL_SCANCODE_S)&&g1.getY() < 400)
        g1.setY(g1.getY()+1);

    return true;
}

bool player2Update(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    if(i.isKeyDown(SDL_SCANCODE_UP)&&g1.getY()!=0)
        g1.setY(g1.getY()-1);
    if(i.isKeyDown(SDL_SCANCODE_DOWN)&&g1.getY() < 400)
        g1.setY(g1.getY()+1);

    return true;
}

int main(int argc, char* argv[])
{
    bool(*p1Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*p2Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*ballUpdate)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    p1Update = &player1Update;
    p2Update = &player2Update;

    GameUI* test = new GameUI(0, 0, "text1", {255,0,0}, 50, "assets/test.ttf", "jellp");
    GameMob* player1 = new GameMob(0, 200, "player1", 100, 100, 0, 0, "error");
    GameMob* player2 = new GameMob(900, 200, "player2", 100, 100, 0, 0, "error");
    player1->setUpdate(p1Update);
    player2->setUpdate(p2Update);

    GameEngine game;
    game.addGameObject(test);
    game.addGameObject(player1);
    game.addGameObject(player2);
    game.run();
    //game.winCondition(func);
    return 0;
}
