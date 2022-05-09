#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

extern short redrawScreen;
extern char megaState, curr_state, color;
extern int blink_limit, count;
/* draws an hourglass shape */
void update_shape(void);
void mega_move(void);
void draw_diamond(char center, char height, u_int shapeColor);
void color_diamond();
void mega_shoot(void);

#endif // _DRAW_SHAPES_H_
