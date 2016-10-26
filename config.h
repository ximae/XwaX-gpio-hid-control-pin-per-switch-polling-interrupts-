/***** config.h *****/

/*
 *   Configure your Gpio pins here with wiringpi numeration
 * 
 * example :
 * up = 1; will assign pin 1 to the up cursor switch
 *
 * asigno the unused functions to unused pin numbers or inexistant ones.
 *
 */


#ifndef _CONFIG_H_
#define _CONFIG_H_

       
        /*cursors*/

	int up =    50;  // seek up
        int down =  50;  // seek down
        int left =  23;  // folder up
        int right = 24;  // folder down

        /* rotary*/
         
         int rot1_pin_a = 26; // rotary 1 pin a
         int rot1_pin_b = 27; // rotary 1 pin a
         
         int rot2_pin_a = 50; // rotary 2 pin a
         int rot2_pin_b = 50; // rotary 2 pin a

        /* deck 1 */

        int f1 =  5;   // load to deck1
        int f2 =  4;   // set time deck1
        int f3 =  1;   // toggle vinyl control deck1
        int cf3 = 8;   // toggle available timecodes deck1 (control+f3)
        int sf5 = 0;   // clone deck2 into deck1 (shift+f5)
        int sf9 = 50;   // clone deck3 into deck1 (shift+f9)
        

        /* deck 2 */

        int f5 =  13;   // load to deck2
        int f6 =  2;   // set time deck2
        int f7 =  3;   // toggle vinyl control deck2
        int cf7 = 9;   // toggle available timecodes deck2 (control+f7)
        int sf2 = 6;   // clone deck1 into deck2 (shift+f2)         
        int sf10 = 50;   // clone deck3 into deck2 (shift+f9)

        /* deck 3 */

        int f9 =   50;   // load to deck3
        int f10 =  50;   // set time deck3
        int f11 =  50;   // toggle vinyl control deck3
        int cf11 = 50;   // toggle available timecodes deck3 (control+f11)
        int sf3 =  50;   // clone deck1 into deck3 (shift+f3)
        int sf7 =  50;   // clone deck2 into deck3 (shift+f7)

        /* additional controls */

        int cst =  22;   // folder rescan (control+shift+tab)
        int ctab = 50;   // toggle track sorting (control+tab)
    
#endif
