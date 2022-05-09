#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void buzzerOff() {
  buzzer_set_period(0);
}

static int song_one_count = 0;
void tetris() {                   //  Tetris theme
   song_one_count ++;
   
   if (song_one_count == 100) // G quarter
     buzzer_set_period(numerator/G_5); 
   if (song_one_count == 200) // D quarter
     buzzer_set_period(numerator/D_5); 
   if (song_one_count == 300) // Eb eighth
     buzzer_set_period(numerator/Eb_5);   
   if (song_one_count == 350) // F quarter
     buzzer_set_period(numerator/F_5); 
   if (song_one_count == 450) // Eb eight
     buzzer_set_period(numerator/Eb_5); 
   if (song_one_count == 500) // D quarter 
     buzzer_set_period(numerator/D_5); 
   if (song_one_count == 600) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count == 690) // off
     buzzer_set_period(0);
   if (song_one_count == 700) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count == 800) // Eb eighth
     buzzer_set_period(numerator/Eb_5); 
   if (song_one_count == 850) // G quarter
     buzzer_set_period(numerator/G_5); 
   if (song_one_count == 950) // F quarter
     buzzer_set_period(numerator/F_5); 
   if (song_one_count == 1050) // Eb eighth
     buzzer_set_period(numerator/Eb_5); 
   if (song_one_count == 1100) // D quarter
     buzzer_set_period(numerator/D_5); 
   if (song_one_count == 1200) // Eb eighth
     buzzer_set_period(numerator/Eb_5); 
   if (song_one_count == 1250) // F quarter
     buzzer_set_period(numerator/F_5);
   if (song_one_count == 1350) // G quarter
     buzzer_set_period(numerator/G_5);
   if (song_one_count == 1450) // Eb eighth 
     buzzer_set_period(numerator/Eb_5);
   if (song_one_count == 1500) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count == 1590) // off
     buzzer_set_period(0);
   if (song_one_count == 1600) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count == 1700) // quarter rest 
     buzzer_set_period(0);
   if (song_one_count == 1800) // eight rest
     buzzer_set_period(0);
   if (song_one_count == 1850) // F quarter
     buzzer_set_period(numerator/F_5);
   if (song_one_count == 1950) // Ab eight
     buzzer_set_period(numerator/Ab_5);
   if (song_one_count == 2000) // chigh quarter
     buzzer_set_period(numerator/C_6);
   if (song_one_count == 2100) // Bb eighth
     buzzer_set_period(numerator/Bb_5);
   if (song_one_count == 2150) // Ab eighth
     buzzer_set_period(numerator/Ab_5);
   if (song_one_count == 2200) // G quarter
     buzzer_set_period(numerator/G_5);
   if (song_one_count == 2300) // Eb eighth
     buzzer_set_period(numerator/Eb_5);
   if (song_one_count == 2350) // G quarter
     buzzer_set_period(numerator/G_5);
   if (song_one_count == 2450) // F quarter
     buzzer_set_period(numerator/F_5);
   if (song_one_count == 2550) // Eb eighth
     buzzer_set_period(numerator/Eb_5);
   if (song_one_count == 2600) // D quarter
     buzzer_set_period(numerator/D_5);
   if (song_one_count == 2690) // off
     buzzer_set_period(0);
   if (song_one_count == 2700) // D quarter
     buzzer_set_period(numerator/D_5);
   if (song_one_count == 2800) // Eb eighth
     buzzer_set_period(numerator/Eb_5);
   if (song_one_count == 2850) // F quarter
     buzzer_set_period(numerator/F_5);
   if (song_one_count == 2950) // G quarter
     buzzer_set_period(numerator/G_5);
   if (song_one_count == 3050) // Eb eighth
     buzzer_set_period(numerator/Eb_5);
   if (song_one_count == 3100) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count == 3190) // off
     buzzer_set_period(0);
   if (song_one_count == 3200) // C quarter
     buzzer_set_period(numerator/C_5);
   if (song_one_count >= 3300){ // off
     buzzer_set_period(0);
     song_one_count = 0;
   }
}

    
    
  

