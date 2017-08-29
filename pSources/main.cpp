#include "gameEngine.h"
#include "gameObject.h"
#include "gameMob.h"
#include "gameUI.h"
#include "collision.h"

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

bool ballUpdate(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    if(g1.getStat(0) == 0)
    {
        g1.setStat(0, -1);
    }

    g1.setX(g1.getX()+g1.getStat(0));

    std::vector<GameObject*>::iterator iter;

    for(iter = g2.begin(); iter < g2.end(); iter++)
    {
        if((*iter)->getName() == "p1" || (*iter)->getName() == "p2")
        {
            if(detectCollision(&g1, (*iter)))
                g1.setStat(0, g1.getStat(0)*-1);
        }
    }

    return true;

}

int main(int argc, char* argv[])
{
    bool(*p1Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*p2Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*bUpdate)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);

    p1Update = &player1Update;
    p2Update = &player2Update;
    bUpdate = &ballUpdate;

    GameEngine game;
    game.loadTexture("p1", "assets/player.png");
    game.loadTexture("p2", "assets/player.png");
    game.loadTexture("b", "assets/ball.png");

    GameUI* player1Title = new GameUI(200, 0, "text1", {255,255,255}, 50, "Player 1", "assets/test.ttf");
    GameUI* player2Title = new GameUI(600, 0, "text2", {255,255,255}, 50, "Player 2", "assets/test.ttf");
    GameMob* player1 = new GameMob(0, 200, "p1", 20, 100, 0, 0);
    GameMob* player2 = new GameMob(980, 200, "p2", 20, 100, 0, 0);
    GameMob* ball = new GameMob(490, 240, "b", 20, 20, 0, 0);

    player1->setUpdate(p1Update);
    player2->setUpdate(p2Update);
    ball->setUpdate(bUpdate);

    game.addGameObject(player1Title);
    game.addGameObject(player2Title);
    game.addGameObject(player1);
    game.addGameObject(player2);
    game.addGameObject(ball);
    game.run();
    //game.winCondition(func);
    return 0;
}
