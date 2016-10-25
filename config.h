/***** config.h *****/

/*
 *   Configure your Gpio pins here with wiringpi numeration
 * 
 * example :
 * up = 1; will assign pin 1 to the up cursor switch
 *
 * asigno the unused functions to unused pin numbers.
 *
 */


#ifndef _CONFIG_H_
#define _CONFIG_H_

       
        /*cursors*/

	int up =    0;  // seek up
        int down =  0;  // seek down
        int left =  0;  // folder up
        int right = 0;  // folder down

        /* rotary*/
         
         int rot1_pin_a = 4; // rotary 1 pin a
         int rot1_pin_b = 5; // rotary 1 pin a
         
         int rot2_pin_a = 0; // rotary 2 pin a
         int rot2_pin_b = 0; // rotary 2 pin a

        /* deck 1 */

        int f1 =  0;   // load to deck1
        int f2 =  0;   // set time deck1
        int f3 =  0;   // toggle vinyl control deck1
        int cf3 = 0;   // toggle available timecodes deck1 (control+f3)
        int sf5 = 0;   // clone deck2 into deck1 (shift+f5)
        int sf9 = 0;   // clone deck3 into deck1 (shift+f9)
        

        /* deck 2 */

        int f5 =  0;   // load to deck2
        int f6 =  0;   // set time deck2
        int f7 =  0;   // toggle vinyl control deck2
        int cf7 = 0;   // toggle available timecodes deck2 (control+f7)
        int sf2 = 0;   // clone deck1 into deck2 (shift+f2)         
        int sf10 = 0;   // clone deck3 into deck2 (shift+f9)

        /* deck 3 */

        int f9 =   0;   // load to deck3
        int f10 =  0;   // set time deck3
        int f11 =  0;   // toggle vinyl control deck3
        int cf11 = 0;   // toggle available timecodes deck3 (control+f11)
        int sf3 =  0;   // clone deck1 into deck3 (shift+f3)
        int sf7 =  0;   // clone deck2 into deck3 (shift+f7)

        /* additional controls */

        int cst =  0;   // folder rescan (control+shift+tab)
        int ctab = 0;   // toggle track sorting (control+tab)
    
#endif