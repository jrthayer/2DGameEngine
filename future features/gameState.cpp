#include "gameState.h"

GameState::GameState()
{

}

/*
DESCRIPTION
    Adds a GameObject to the GameState's vector of GameObjects
===================================================================
INPUTS:
    GameObject *g_object = game object that is part of this game
                           state
===================================================================
NOTE: needs to be pass by pointer because a derived class cannot be
      properly stored in a vector.
*/
void GameState::addObject(GameObject *g_object)
{
    m_g_objects.push_back(g_object);
}

/*
DESCRIPTION
    Calls the draw function on all the GameObjects in the
    m_g_objects vector
===================================================================
INPUTS:
    TextureManager &t_manager = pass by reference the TextureManager
                                that will draw the GameObjects
===================================================================
NOTE: needs to be pass by reference since we need the game's
      TextureManager to draw the gameObject to the SDL renderer
      connected to the game window
*/
void GameState::draw(TextureManager &t_manager)
{
    std::vector<GameObject*>::iterator iter;

    for(iter = m_g_objects.begin(); iter < m_g_objects.end(); iter++)
    {
        (*iter)->draw(t_manager);
    }
}

/*
DESCRIPTION
    Calls the update function on all the GameObjects in the
    m_g_objects vector and handles collision between each
    GameObject
===================================================================
*/
void GameState::update()
{

}

/*
DESCRIPTION
    Sets the member variable that identifies which GameState to
    go to after this one
===================================================================
*/
void GameState::setNextState(GameState* next)
{
    m_next_state = next;
}

/*
DESCRIPTION
    Gets the member variable that identifies which GameState to
    go to after this one
===================================================================
*/
GameState* GameState::getNextState()
{
    return m_next_state;
}

