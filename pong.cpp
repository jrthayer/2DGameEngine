#include "gameEngine.h"

#include <vector>
#include <string>
#include <iostream>
#include <math.h>


#define PI 3.145159625
double maxBounceAngle = 75*PI/180;
double ballSpeed = 1;

//calculates reflection angle based on original pong
double bounceAngle(GameObject& g1, GameObject& g2)
{
    double paddleMiddle = g2.getHeight()/2;
    double distanceFromMiddle = g2.getY()+ paddleMiddle - g1.getY()-g1.getHeight()/2;
    double normalizedDFM = distanceFromMiddle/paddleMiddle;
    double angle = normalizedDFM * maxBounceAngle;

    return angle;
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

bool score1Update(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    std::vector<GameObject*>::iterator iter;

    for(iter = g2.begin(); iter < g2.end(); iter++)
    {
        if((*iter)->getName() == "b")
        {
            if((*iter)->getStat(3) == 1 && (*iter)->getStat(2) == 1)
            {
                g1.setStat(1,g1.getStat(1)+1);
                (*iter)->setStat(2,0);
                return true;
            }
        }
    }
    return false;
}

bool score2Update(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    std::vector<GameObject*>::iterator iter;

    for(iter = g2.begin(); iter < g2.end(); iter++)
    {
        if((*iter)->getName() == "b")
        {
            if((*iter)->getStat(3) == 2 && (*iter)->getStat(2) == 1)
            {
                g1.setStat(1,g1.getStat(1)+1);
                (*iter)->setStat(2,0);
                return true;
            }
        }
    }
    return false;
}

bool ballUpdate(GameObject &g1, std::vector<GameObject*> &g2, InputManager &i)
{
    if(g1.getStat(0) == 0)
    {
        if(g1.getStat(3) == 1)
        {
            //if(i.isKeyDown(SDL_SCANCODE_W)||i.isKeyDown(SDL_SCANCODE_S))
                g1.setStat(0, 1*ballSpeed);
                g1.setStat(1, 0*ballSpeed);
        }
        else if(g1.getStat(3) == 2)
        {
            //if(i.isKeyDown(SDL_SCANCODE_UP)||i.isKeyDown(SDL_SCANCODE_DOWN))
                g1.setStat(0, -1*ballSpeed);
                g1.setStat(1, 0*ballSpeed);
        }
    }

    g1.setX(g1.getX()+g1.getStat(0));
    g1.setY(g1.getY()+g1.getStat(1));

    std::vector<GameObject*>::iterator iter;

    for(iter = g2.begin(); iter < g2.end(); iter++)
    {
        if((*iter)->getName() == "p1")
        {
            if(detectCollision(&g1, (*iter)))
            {
                double bAngle = bounceAngle(g1, (**iter));

                g1.setStat(0, ballSpeed*cos(bAngle));
                g1.setStat(1, ballSpeed*-sin(bAngle));

            }
            else if(g1.getX() >= 960+ballSpeed+1)
            {
                g1.setStat(0, 1*ballSpeed);
                g1.setStat(1, 0*ballSpeed);
                g1.setStat(2, 1);
                g1.setStat(3, 1);

                g1.setX((*iter)->getX()+(*iter)->getWidth());
                g1.setY((*iter)->getY()+(*iter)->getHeight()/2-g1.getHeight()/2);
            }
        }
        else if((*iter)->getName() == "p2")
        {
            if(detectCollision(&g1, (*iter)))
            {
                double bAngle = bounceAngle(g1, (**iter));

                g1.setStat(0, ballSpeed*-cos(bAngle));
                g1.setStat(1, ballSpeed*-sin(bAngle));
            }
            else if(g1.getX() <= 20-ballSpeed-1)
            {
                g1.setStat(0, -1*ballSpeed);
                g1.setStat(1, 0*ballSpeed);
                g1.setStat(2, 1);
                g1.setStat(3, 2);

                g1.setX((*iter)->getX()- g1.getWidth());
                g1.setY((*iter)->getY()+(*iter)->getHeight()/2-g1.getHeight()/2);

            }
        }

        if(g1.getY() <= 0)
        {
            g1.setStat(1, g1.getStat(1)*-1);
        }
        else if(g1.getY()+g1.getHeight() >= 500)
        {
            g1.setStat(1, g1.getStat(1)*-1);
        }

    }

    return true;
}

int main(int argc, char* argv[])
{
    bool(*p1Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*p2Update)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*p1ScoreUpdate)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*p2ScoreUpdate)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);
    bool(*bUpdate)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager);

    p1Update = &player1Update;
    p2Update = &player2Update;
    p1ScoreUpdate = &score1Update;
    p2ScoreUpdate = &score2Update;
    bUpdate = &ballUpdate;

    GameEngine game;
    game.loadTexture("p1", "assets/player.png");
    game.loadTexture("p2", "assets/player.png");
    game.loadTexture("b", "assets/ball.png");

    GameUI* player1Title = new GameUI(200, 0, "text1", {255,255,255}, 50, "Player 1", "assets/test.ttf");
    GameUI* player2Title = new GameUI(600, 0, "text2", {255,255,255}, 50, "Player 2", "assets/test.ttf");
    GameUI* player1Score = new GameUI(300, 50, "text3", {255,255,255}, 50, "0", "assets/test.ttf");
    GameUI* player2Score = new GameUI(700, 50, "text4", {255,255,255}, 50, "0", "assets/test.ttf");
    GameMob* player1 = new GameMob(0, 200, "p1", 20, 100, 0, 0);
    GameMob* player2 = new GameMob(980, 200, "p2", 20, 100, 0, 0);
    GameMob* ball = new GameMob(960, 240, "b", 20, 20, 0, 0);

    ball->setStat(3,2);
    player1Score->setStat(0,1);
    player2Score->setStat(0,1);

    player1->setUpdate(p1Update);
    player2->setUpdate(p2Update);
    player1Score->setUpdate(p1ScoreUpdate);
    player2Score->setUpdate(p2ScoreUpdate);
    ball->setUpdate(bUpdate);

    game.addGameObject(player1Title);
    game.addGameObject(player2Title);
    game.addGameObject(player1Score);
    game.addGameObject(player2Score);
    game.addGameObject(player1);
    game.addGameObject(player2);
    game.addGameObject(ball);
    game.run();

    return 0;
}
