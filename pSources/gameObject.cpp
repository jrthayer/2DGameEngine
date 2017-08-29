#include "gameObject.h"

/*
DESCRIPTION
    Initializes member variables
===================================================================
*/
GameObject::GameObject(double x, double y, double w, double h, std::string name)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_name(name)
{

}

/*
DESCRIPTION
    Runs the function passed in through setUpdate
===================================================================
*/
void GameObject::update(GameObject &g1, std::vector<GameObject*> &g2,
    InputManager &i_manager)
{
    if(m_update != NULL)
        m_update(g1, g2, i_manager);
}

/*
DESCRIPTION
    Sets local function to function past in from user, this allows
    for user defined behavior to be programmed into the class
===================================================================
INPUTS:
    bool(*func)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager) = function pointer to function defined by user
===================================================================
*/
void GameObject::setUpdate(bool(*func)(GameObject&, std::vector<GameObject*>&, InputManager &i_manager))
{
    m_update = func;
}
