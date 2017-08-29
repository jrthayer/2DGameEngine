#include "gameEngine.h"

GameEngine::GameEngine()
{

}

void GameEngine::run()
{
    m_running = true;

    while(m_running)
    {
        draw(m_t_manager);
        update();
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
    std::vector<GameObject*>::iterator iter2;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        for(iter2 = m_g_objects.begin(); iter<m_g_objects.end(); iter++)
        {
            if(*iter != *iter2)
                (*iter)->update(*iter2, m_i_manager);
        }
    }
}

void GameEngine::draw(TextureManager t_manager)
{
    std::vector<GameObject*>::iterator iter;
    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {

        (*iter)->draw(t_manager);
    }

    t_manager.render();
}

void GameEngine::addGameObject(GameObject* g_object)
{
    m_g_objects.push_back(g_object);
}

bool GameEngine::winCondition(bool(*func)(std::vector<GameObject*>*))
{
    if(func(&m_g_objects) == true)
        return true;
    else
        return false;
}
