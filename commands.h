#ifndef COMMANDS_H
#define COMMANDS_H

#include <math.h>
enum controls : int
{
    PFORWARD = 1,
	PBACK = 2,
	RLEFT = 4,
	RRIGHT = 8,
	YLEFT = 16,
	YRIGHT = 32,
	TUP = 64,
	TDOWN = 128,
};

inline bool isCmdSet(int cmd, int ctrl)
{
    if((cmd & ctrl) == ctrl)
    {
        return true;
    }
    return false;
}

inline void setControls(int cmd, float& x, float& y, float& z, float& yaw)
{
    const int len = 8;
    int commands[len] = {PFORWARD, PBACK, RLEFT, RRIGHT, YLEFT, YRIGHT, TUP, TDOWN};
    for(int i = 0; i < len; ++i)
    {
        if(!isCmdSet(cmd, commands[i]))
        {
            continue;
        }
        switch(commands[i])
        {
            case PFORWARD:
                x += 5.0;
            break;
            case PBACK:
                x -= 5.0;
            break;
            case RLEFT:
                y -= 5.0;
            break;
            case RRIGHT:
                y += 5.0;
            break;
            case TUP:
                z -= 5.0;
            break;
            case TDOWN:
                z += 5.0;
            break;
            case YLEFT:
                yaw -= M_PI / 10;
            break;
            case YRIGHT:
                yaw += M_PI / 10;
            break;
        }
    }

}

#endif

