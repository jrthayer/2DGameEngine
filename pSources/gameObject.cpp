#include "gameObject.h"

/*
DESCRIPTION
    Initializes member variables
===================================================================
*/
GameObject::GameObject(int x, int y)
    : m_x(x), m_y(x)
{

}

/*
DESCRIPTION
    Runs the function passed in through setUpdate
===================================================================
*/
void GameObject::update(GameObject *g, InputManager &i_manager)
{
    if(m_update != NULL)
        m_update(*g, i_manager);
}

/*
DESCRIPTION
    Sets local function to function past in from user, this allows
    for user defined behavior to be programmed into the class
===================================================================
INPUTS:
    void(*func)() = function pointer to function defined by user
===================================================================
*/
void GameObject::setUpdate(void(*func)(const GameObject&, InputManager &i_manager))
{
    m_update = func;
}
