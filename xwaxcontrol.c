/*
 * 
 *
 *
 *	How to test:
 *	  Use the SoC's pull-up and pull down resistors that are avalable
 *	on input pins. So compile & run this program (via sudo), then
 *	in another terminal:
 *		gpio mode 0 up
 *		gpio mode 0 down
 *	at which point it should trigger an interrupt. Toggle the pin
 *	up/down to generate more interrupts to test.
 *
 * compile:
 *
 * gcc -Wall -o keycontrol keycontrol.c rotaryencoder.c keysend.c -lwiringPi -lpthread
 *
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include "rotaryencoder.h"
#include "config.h"


#define	DEBOUNCE_TIME	200

// globalComparator:

  int uinp_fd;


/*********** Functions ************/


/* rotary loop thread */


PI_THREAD (rotary_loop) {

 while (1) {

   long l = encoder -> value;
   if (l != value) {
	
	       if ( l > value) { send_Up();  }
     	
	       if ( l < value) { send_Down(); }	
            
            value = l;
	    }

	delay(50);    
  }
}


/* pendrive mount and rescan function */


void penmount(void) {
  system("umount /dev/sda1");	    
   sleep(1);
  system("mount /dev/sda1 /media/odroid/usbdrive");
   sleep(1);
  send_CST();
   sleep(1);
}


/* myInterrupts functions */


void myInterrupt0 (void) { 
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else { 
         send_F1() ;
         delay(100);
        }
   while (digitalRead (f1) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt1 (void) { 
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else {
         send_F2();
         delay(100);
        }
   while (digitalRead (f2) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt2 (void) { 
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else { 
         send_F3() ;
         delay(100);
        }
   while (digitalRead (f3) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt3 (void) { 
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else { send_F5() ;
          delay(100); 
        }
   while (digitalRead (f5) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt4 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else {
         send_F6() ;
         delay(100); 
        }
   while (digitalRead (f6) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt5 (void) {
  int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else {
         send_F7();
         delay(100);
        }
   while (digitalRead (f7) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
 }

void myInterrupt6 (void) { 
  int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else {
         send_Left(); 
         delay(300);
        }
}

void myInterrupt7 (void) { 
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else {
         send_Right() ; 
         delay(300);
        }
}

void myInterrupt8 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else send_SF2() ;
   while (digitalRead (sf2) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
}

void myInterrupt9 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else send_SF5() ; 
   while (digitalRead (sf5) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
}

void myInterrupt10 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else  penmount() ;
   while (digitalRead (cst) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
}

void myInterrupt11 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else send_CF3() ; 
   while (digitalRead (cf3) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
}

void myInterrupt12 (void) {
   int debounceTime = DEBOUNCE_TIME ;
   if (millis () < debounceTime)
      {
	debounceTime = millis () + DEBOUNCE_TIME ;
      }
   else send_CF7() ; 
   while (digitalRead (cf7) == HIGH) {
      delay (1) ;
      debounceTime = millis () + DEBOUNCE_TIME ;
     }
}


 /*
 *********************************************************************************
 * main
 *********************************************************************************
 */

int main (void) {

//setup devices

if ((uinp_fd = setup_uinput_device()) < 0) {
   printf("Unable to find uinput device\n");
   return -1;
  }

  wiringPiSetup() ;
  
  sleep(3);


   wiringPiISR (f1, INT_EDGE_FALLING, myInterrupt0);
   wiringPiISR (f2, INT_EDGE_FALLING, myInterrupt1);
   wiringPiISR (f5, INT_EDGE_FALLING, myInterrupt3);
   wiringPiISR (f6, INT_EDGE_FALLING, myInterrupt4);

   pinMode (left, INPUT) ;
   pinMode (right, INPUT) ;
   pinMode (f3, INPUT) ;
   pinMode (f7, INPUT) ; 
   pinMode (cf3, INPUT) ;
   pinMode (cf7, INPUT) ;
   pinMode (sf2, INPUT) ;
   pinMode (sf5, INPUT) ;
   pinMode (cst, INPUT) ;
   pinMode (ctab, INPUT) ;

pullUpDnControl(left,PUD_DOWN);
pullUpDnControl(right,PUD_DOWN);
pullUpDnControl(f3,PUD_DOWN);
pullUpDnControl(f7,PUD_DOWN);
pullUpDnControl(cf3,PUD_DOWN);
pullUpDnControl(cf7,PUD_DOWN);
pullUpDnControl(sf2,PUD_DOWN);
pullUpDnControl(sf5,PUD_DOWN);
pullUpDnControl(cst,PUD_DOWN);
pullUpDnControl(ctab,PUD_DOWN);

/* Alternate actions config 

   pinMode (up, INPUT) ;
   pinMode (down, INPUT) ;
   pinMode (f9, INPUT) ;
   pinMode (f10, INPUT) ;
   pinMode (f11, INPUT) ;
   pinMode (cf11, INPUT) ;
   pinMode (sf3, INPUT) ;
   pinMode (sf7, INPUT) ;
   pinMode (sf9, INPUT) ;
   pinMode (sf10, INPUT) ;



 pullUpDnControl(up,PUD_DOWN);
 pullUpDnControl(down,PUD_DOWN);
 pullUpDnControl(f1,PUD_DOWN);
 pullUpDnControl(f2,PUD_DOWN);
 pullUpDnControl(f5,PUD_DOWN);
 pullUpDnControl(f6,PUD_DOWN);
 pullUpDnControl(f9,PUD_DOWN);
 pullUpDnControl(f10,PUD_DOWN);
 pullUpDnControl(f11,PUD_DOWN);
 pullUpDnControl(cf11,PUD_DOWN);
 pullUpDnControl(sf3,PUD_DOWN);
 pullUpDnControl(sf7,PUD_DOWN);
 pullUpDnControl(sf9,PUD_DOWN);
 pullUpDnControl(sf10,PUD_DOWN);

*/

struct encoder *encoder = setupencoder(rot1_pin_a,rot1_pin_b);
long value;

int a[24];
int i = 0;
for ( i = 0; i < 24; i = i+1) { a[i] = 0; }

  printf(" waiting...\n");
 

/********* main loops **********/

piThreadCreate (rotary_loop) ;

while  ( a >= 0 ) {
   
     a[0] = digitalRead(left);
     a[1] = digitalRead(right);
     a[2] = digitalRead(f3); 
     a[3] = digitalRead(f7);
     a[4] = digitalRead(cf3);
     a[5] = digitalRead(cf7);
     a[6] = digitalRead(sf2);
     a[7] = digitalRead(sf5);
     a[8] = digitalRead(cst); 
     

   /* alternate pin readings

     a[9] = digitalRead(f1);
     a[10] = digitalRead(f2);
     a[11] = digitalRead(f5);
     a[12] = digitalRead(f6);
     a[13] = digitalRead(f9);
     a[14] = digitalRead(f10);
     a[15] = digitalRead(f11);
     a[16] = digitalRead(cf11);
     a[17] = digitalRead(sf3);
     a[18] = digitalRead(sf7);
     a[19] = digitalRead(sf9);
     a[20] = digitalRead(sf10);
     a[21] = digitalRead(ctab);
     a[22] = digitalRead(up);
     a[23] = digitalRead(down);
     
   */

   if ( a[0] > 0 ) {
     myInterrupt6();
     a[0]= 0;
    }

    if ( a[1] > 0 ) {
     myInterrupt7();
     a[1]= 0;
    }

   if ( a[2] > 0) {
      myInterrupt2();
      a[2] = 0;    
    }

   if ( a[3]> 0 ) {
     myInterrupt5();
     a[3] = 0;
    } 

   if ( a[4]> 0) {
     myInterrupt11();
     a[4] = 0;
    }
    
   if ( a[5] > 0) {
     myInterrupt12();
     a[5] = 0;
    }
   
   if ( a[6] > 0 ) {
    myInterrupt8();
     a[6]= 0;
    }

    if ( a[7] > 0 ) {
     myInterrupt9();
     a[7]= 0;
    }

    if ( a[8] > 0 ) {
     myInterrupt10();
     a[8]= 0;
    } 

   usleep(10000);
  }

return 0;  

}
