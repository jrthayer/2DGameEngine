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
        m_t_manager.render();
        //call event handler
        //call game handler
            //call texture handler
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
