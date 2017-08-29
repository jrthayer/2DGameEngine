#include "gameEngine.h"

GameEngine::GameEngine()
{
}

void GameEngine::run()
{
    TextureManager m_t_manager;

    m_running = true;

    while(m_running)
    {
        update();
        draw();
    }

    close();

}

void GameEngine::close()
{
    //destroy event handler
    //destroy game handler
    //destroy texture handler
    SDL_Quit();
}

void GameEngine::update()
{
    std::vector<GameObject*>::iterator iter;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        (*iter)->update();
    }
}

void GameEngine::draw()
{
    std::vector<GameObject*>::iterator iter;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        (*iter)->draw(t_manager);
    }
}

void GameEngine::addGameState(GameState* g_object)
{
    m_g_objects.push_back(g_object);
}
