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
        draw(m_t_manager);
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

void GameEngine::draw(TextureManager t_manager)
{
    std::vector<GameObject*>::iterator iter;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        (*iter)->draw(t_manager);
    }
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
