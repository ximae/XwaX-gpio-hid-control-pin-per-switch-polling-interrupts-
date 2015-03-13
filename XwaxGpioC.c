/* binary encoded gpio uinput keystroke generation program */

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

// global
int uinp_fd;
int bite [4] ;


/*
 * Functions
 *********************************************************************************
 */

// interrupts

void myInterrupt0 (void) { bite[0] = 1; }
void myInterrupt1 (void) { bite[1] = 1; }
void myInterrupt2 (void) { bite[2] = 1; }
void myInterrupt3 (void) { bite[3] = 1; }



/* Setup the uinput device Function

int setup_uinput_device() {
 uinp_fd = open("/dev/uinput", O_WRONLY | O_NDELAY);
 if (uinp_fd == 0) {
   printf("Unable to open /dev/uinput\n");
   return -1;
  }
 struct uinput_user_dev uinp;
 memset(&uinp, 0, sizeof(uinp)); // Intialize the uInput device to NULL
 strncpy(uinp.name, "Virtual Keyboard Device", strlen("Virtual Keyboard Device"));
 
   uinp.id.version = 4;
   uinp.id.bustype = BUS_USB;
   uinp.id.product = 1;
   uinp.id.vendor = 1;
  
// Setup the uinput device
 ioctl(uinp_fd, UI_SET_EVBIT, EV_KEY);
 ioctl(uinp_fd, UI_SET_EVBIT, EV_REL);
 int i = 0;
 for (i = 0; i < 256; i++) {
   ioctl(uinp_fd, UI_SET_KEYBIT, i);
  }
  
// Create input device into input sub-system
 write(uinp_fd, &uinp, sizeof(uinp));
 if (ioctl(uinp_fd, UI_DEV_CREATE)) {
   printf("Unable to create UINPUT device.");
   return -1;
  }
 return uinp_fd;
}

/* actual key sending function */

void send_key_event(int fd, unsigned int keycode, int keyvalue) {
 struct input_event event;
 gettimeofday(&event.time, NULL);
 
   event.type = EV_KEY;
   event.code = keycode;
   event.value = keyvalue;
   
 if (write(fd, &event, sizeof(event)) < 0) {
   printf("simulate key error\n");
  }
  
   event.type = EV_SYN;
   event.code = SYN_REPORT;
   event.value = 0;
   
 write(fd, &event, sizeof(event));
 if (write(fd, &event, sizeof(event)) < 0) {
   printf("simulate key error\n");
  }
}

/*specific keyode sends*/

void send_F1(void)
{
send_key_event(uinp_fd, 59, 1);
send_key_event(uinp_fd, 59, 0);
}

void send_F2(void)
{
send_key_event(uinp_fd, 60, 1);
send_key_event(uinp_fd, 60, 0);
}

void send_F3(void)
{
send_key_event(uinp_fd, 61, 1);
send_key_event(uinp_fd, 61, 0);
}

void send_F5(void)
{
send_key_event(uinp_fd, 63, 1);
send_key_event(uinp_fd, 63, 0);
}

void send_F6(void)
{
send_key_event(uinp_fd, 64, 1);
send_key_event(uinp_fd, 64, 0);
}

void send_F7(void)
{
send_key_event(uinp_fd, 65, 1);
send_key_event(uinp_fd, 65, 0);
}

void send_F9(void)
{
send_key_event(uinp_fd, 67, 1);
send_key_event(uinp_fd, 67, 0);
}

void send_F10(void)
{
send_key_event(uinp_fd, 68, 1);
send_key_event(uinp_fd, 68, 0);
}

void send_F011(void)
{
send_key_event(uinp_fd, 69, 1);
send_key_event(uinp_fd, 69, 0);
}

void send_CF3(void) {
send_key_event(uinp_fd, 29, 1);
send_key_event(uinp_fd, 61, 1);
send_key_event(uinp_fd, 29, 0);
send_key_event(uinp_fd, 61, 0);
}

void send_CF7(void) {
send_key_event(uinp_fd, 29, 1);
send_key_event(uinp_fd, 65, 1);
send_key_event(uinp_fd, 29, 0);
send_key_event(uinp_fd, 65, 0);
}

void send_SF2(void) {
send_key_event(uinp_fd, 42, 1);
send_key_event(uinp_fd, 60, 1);
send_key_event(uinp_fd, 42, 0);
send_key_event(uinp_fd, 60, 0);
}

void send_SF5(void) {
send_key_event(uinp_fd, 42, 1);
send_key_event(uinp_fd, 63, 1);
send_key_event(uinp_fd, 42, 0);
send_key_event(uinp_fd, 63, 0);
}

void send_CTab(void) {
send_key_event(uinp_fd, 29, 1);
send_key_event(uinp_fd, 15, 1);
send_key_event(uinp_fd, 29, 0);
send_key_event(uinp_fd, 15, 0);
}

void send_CST(void) {
send_key_event(uinp_fd, 29, 1);
send_key_event(uinp_fd, 15, 1);
send_key_event(uinp_fd, 42, 1);
send_key_event(uinp_fd, 29, 0);
send_key_event(uinp_fd, 15, 0);
send_key_event(uinp_fd, 42, 0);
}

void send_Left(void)
{
send_key_event(uinp_fd, 105, 1);
send_key_event(uinp_fd, 105, 0);
}

void send_Right(void)
{
send_key_event(uinp_fd, 106, 1);
send_key_event(uinp_fd, 106, 0);
}

void send_Up(void)
{
send_key_event(uinp_fd, 103, 1);
send_key_event(uinp_fd, 103, 0);
}

void send_Down(void)
{
send_key_event(uinp_fd, 108, 1);
send_key_event(uinp_fd, 108, 0);
}




/*
 *********************************************************************************
 * main
 *********************************************************************************
 */

int main (void) {

int x,y,z,a;

  wiringPiSetup() ;

  x = wiringPiISR (0, INT_EDGE_FALLING, myInterrupt0);
  y = wiringPiISR (1, INT_EDGE_FALLING, myInterrupt1);
  z = wiringPiISR (2, INT_EDGE_FALLING, myInterrupt2);
  a=  wiringPiISR (3, INT_EDGE_FALLING, myInterrupt3);
  
  struct encoder *encoder = setupencoder(4,5);
  long value;

  bite[0] = bite [1] = bite [2] = bite[3] = 0;

  printf(" waiting...\n");
 
  while ( x || y || z || a >= 0 ) {
          updateEncoders();
          long l = encoder -> value;
	  if (bite[3] == 0 &&  bite[2] == 0 && bite[1] == 0 && bite[0] == 1) {
	    send_F1();
	    printf(" code for 1: %d %d %i %d \n",bite[3], bite[2], bite[1], bite[0]);
	    delay(100);                                                         
	    bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
          if (bite[3] == 0 && bite[2] == 0 && bite[1] == 1 && bite[0] == 0) {
            printf(" code for 2: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            send_F2();
	    delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
           if (bite[3] == 0 && bite[2] == 0 && bite[1] == 1 && bite[0] == 1) {
            printf(" code for 3: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            send_F3();
	    delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
            if (bite[3] == 0 && bite[2] == 1 && bite[1] == 0 && bite[0] == 0) {
            send_SF2();
	    printf(" code for 4: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
           if (bite[3] == 0 && bite[2] == 1 && bite[1] == 0 && bite[0] == 1) {
            send_CF3();
	    printf(" code for 5: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }    
           if (bite[3] == 0 && bite[2] == 1 && bite[1] == 1 && bite[0] == 0) {
            send_CTab();
	    printf(" code for 6: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
	   if (bite[3] == 0 && bite[2] == 1 && bite[1] == 1 && bite[0] == 1) {
            send_CST();
	    printf(" code for 7: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
	   if (bite[3] == 1 && bite[2] == 0 && bite[1] == 0 && bite[0] == 0) {
            send_F5();
	    printf(" code for 8: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
	    delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
          if (bite[3] == 1 && bite[2] == 0 && bite[1] == 0 && bite[0] == 1) {
            send_F6();
	    printf(" code for 9: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
          if (bite[3] == 1 && bite[2] == 0 && bite[1] == 1 && bite[0] == 0) {
            send_F7();
	    printf(" code for 10: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
          if (bite[3] == 1 && bite[2] == 0 && bite[1] == 1 && bite[0] == 1) {
            send_SF5();
	    printf(" code for 11: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
          if (bite[3] == 1 && bite[2] == 1 && bite[1] == 0 && bite[0] == 0) {
            send_CF7();
	    printf(" code for 12: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
           if (bite[3] == 1 && bite[2] == 1 && bite[1] == 0 && bite[0] == 1) {
            send_Left();
	    printf(" code for 13: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
           if (bite[3] == 1 && bite[2] == 1 && bite[1] == 1 && bite[0] == 0) {
            send_Right();
	    printf(" code for 14: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
           if (bite[3] == 1 && bite[2] == 1 && bite[1] == 1 && bite[0] == 1) {
            /*system("shutdown now");*/
	    printf(" code for 15: %d %d %i %d \n", bite [3], bite[2], bite[1], bite[0]);
            delay(100);
           bite[3] = bite [2] = bite[1] = bite[0] = 0;
           }
	   if (l != value) {
             printf("value: %d\n",(void*)l);
	
	       if ( l > value) { send_Up();  }
     	
	       if ( l < value) { send_Down(); }	
            value = l;	
  }      
  delay(100);
  }
return 0;  
}
