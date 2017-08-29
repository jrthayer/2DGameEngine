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
    m_i_manager.update();

    std::vector<GameObject*>::iterator iter;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        (*iter)->update(**iter, m_g_objects, m_i_manager);
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

void GameEngine::loadTexture(std::string id, const char* file)
{
    m_t_manager.load(id,file);
}

bool GameEngine::winCondition(bool(*func)(std::vector<GameObject*>*))
{
    if(func(&m_g_objects) == true)
        return true;
    else
        return false;
}
