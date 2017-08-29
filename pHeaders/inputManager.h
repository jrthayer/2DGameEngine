#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SDL.h>

/*
DESCRIPTION
    The InputManager is responsible for capturing, storing, and
    returning the current state of the keyboard.
===================================================================
*/
class InputManager
{
    public:
        void update();
        void isKeyDown();

    private:
        const Uint8* m_keystates = 0;
        int m_x, m_y;

        void storeKeyboard();
};
#endif // INPUTMANAGER_H
