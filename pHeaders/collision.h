#ifndef COLLISION_H
#define COLLISION_H

#include "gameObject.h"
#include "gameMob.h"

inline bool detectCollision(GameObject* g1, GameObject* g2)
{
	if(g1->getX() + g1->getWidth() <= g2->getX() )
		return false;

	if(g2->getX() + g2->getWidth()  <= g1->getX() )
		return false;

	if(g1->getY() + g1->getHeight()  <= g2->getY() )
		return false;

	if(g2->getY() + g2->getHeight()  <= g1->getY() )
		return false;

	return true;
}

inline bool detectCursorInside(int cursorX, int cursorY, int x, int y, int width, int height)
{
	if(cursorX >= x + width || cursorX <= x)
		return false;

	if(cursorY >= y + height || cursorY <= y)
		return false;

	return true;
}
#endif // COLLISION_H
