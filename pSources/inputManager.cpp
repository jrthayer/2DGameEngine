#include "inputManager.h"

/*
DESCRIPTION
    Stores keyboard state and mouse location if a key has been
    pressed, if a key has been released, and if the mouse has
    been moved
===================================================================
*/
void InputManager::update()
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_KEYDOWN:
                storeKeyboard();
                break;

            case SDL_KEYUP:
                storeKeyboard();
                break;

            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&m_x, &m_y);
                break;

            default:
                break;
        }
    }
}

/*
DESCRIPTION
    Grabs the state of the keyboard and stores it in m_keystates
===================================================================
*/
void InputManager::storeKeyboard()
{
    m_keystates = SDL_GetKeyboardState(0);
}

/*
DESCRIPTION
    Checks if a specific key is down
===================================================================
INPUTS:
    SDL_Scancode key = key who's state is checked
===================================================================
OUTPUTS:
    Returns True if the key is currently down
===================================================================
*/
bool InputManager::isKeyDown(SDL_Scancode key)
{
    if(m_keystates != 0)
    {
        if(m_keystates[key] == 1)
            return true;
        else
            return false;
    }
    return false;
}
