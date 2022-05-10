#include "draw_shapes.h"

void color_diamond(){
  switch(color){
      case 0:
	draw_diamond(60,60,COLOR_YELLOW);
	color++;
	break;
      case 1:
	draw_diamond(60,60,COLOR_PURPLE);
	color++;
	break;
      case 2:
	draw_diamond(60,60,COLOR_GREEN);
	color++;
	break;
      case 3:
	draw_diamond(60,60,COLOR_HOT_PINK);
	color = 0;
	break;
  }
}
