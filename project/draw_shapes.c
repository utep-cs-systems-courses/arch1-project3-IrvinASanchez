#include "draw_shapes.h"    
#include "switches.h"

short redrawScreen = 1;
char megaState = 1;
char curr_state = 0;
int blink_limit = 35;
char color =0;

void mega_move(void)
{
    if (blink_limit>30){
        if (megaState){
            drawMega(50,64);
            drawString11x16(15,5,"MEGA MAN", COLOR_BLACK, COLOR_BLUE);
        }
        else {
            drawMega2(50,64);
            drawString11x16(15,5,"MEGA MAN", COLOR_GREEN, COLOR_BLUE);
        }
    }
    else{
        blink_limit = 100;
        drawString5x7(30,130,"PRESS START", COLOR_RED, COLOR_BLUE);
    }
}

void draw_diamond(char center,char height, u_int shapeColor)
{
    for (u_char r = 0; r<11; r++){
        for(u_char c = 0; c<=r; c++){
	  drawPixel(center+c, height+r, shapeColor);
	  drawPixel(center-c, height+r, shapeColor);
	  //drawString8x12(30,130,"PRESS START", COLOR_RED, COLOR_BLUE);
        }
    }
    for (u_char c = 0; c<11; c++){
        for(u_char r = 10; r<=20-c; r++){
            drawPixel(center+c, height+r, shapeColor);
            drawPixel(center-c, height+r, shapeColor);
        }
    }
}

int count = 0;
void mega_shoot(void)
{
  drawMega2(10,64);
  if(count == 1){
    for(int i = 45; i < 100; i++){ 
      drawShoot(i,64);
    }
    count++;
  }
  if(count == 2){
    for(int i = 45; i < 100; i++){
      drawShoot(i,64);
    }
    count++;
  }
  if(count == 90){
     drawShoot(80,64);
     count++;
  }
  if(count >= blink_limit)
    count=0;
}
