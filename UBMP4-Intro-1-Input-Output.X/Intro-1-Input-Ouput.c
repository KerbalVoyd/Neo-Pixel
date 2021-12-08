/*==============================================================================
 Project: Intro-1-Input-Output
 Date:    May 16, 2021
 
 This example UBMP4 input and output program demonstrates pushbutton input, LED
 (bit) output, port latch (byte) output, time delay functions, and simple 'if'
 condition structures.
 
 Additional program analysis and programming activities demonstrate byte output,
 logical condition operators AND and OR, using delay functions to create sound,
 and simulated start-stop button functionality.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// The main function is required, and the program begins executing from here.
void neopixel_send(unsigned char colour);
void neopixel_fill_a(unsigned char leds, unsigned char red[], unsigned char green[], unsigned char blue[]);
void neopixel_fill(unsigned char leds, unsigned char red, unsigned char green, unsigned char blue);
unsigned char leds;
unsigned char red, green, blue;
unsigned char redArray[9], greenArray[9], blueArray[9];
int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        int prevNum = 4;
        int leftNum = 3;
        int prevLeftNum = 4;
        // If SW2 is pressed, make a flashy light pattern
//        for (int i3 = 0; i3 < 256; i3++) {
//                
//                redArray[4]++;
//                neopixel_fill_a(9, redArray, greenArray, blueArray);
//                
//                __delay_us(500);
//            }
        for (int i = 5; i = 8; i++) {
            for (int ii = 0; ii < 256; ii++) {
                
                redArray[i]++;
                redArray[leftNum]++;
                redArray[prevNum]--;
                redArray[prevLeftNum]--;
                neopixel_fill_a(9, redArray, greenArray, blueArray);
                
                __delay_us(500);
            }
            prevLeftNum = leftNum;
            leftNum--;
            prevNum = i;
            
        }
        // Add code for your Program Analysis and Programming Activities here:

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

void neopixel_fill_a(unsigned char leds, unsigned char red[], unsigned char green[], unsigned char blue[]) {
    int ledNum = 0;
    for(; ledNum != leds; ledNum++) {
        neopixel_send(green[ledNum]);
        neopixel_send(red[ledNum]);
        neopixel_send(blue[ledNum]);
    }
}

void neopixel_fill(unsigned char leds, unsigned char red, unsigned char green, unsigned char blue) {
    for (; leds != 0; leds--) {
        neopixel_send(green);
        neopixel_send(red);
        neopixel_send(blue);
    }
    
}

void neopixel_send(unsigned char colour)
{
    for(unsigned char bits = 8; bits != 0; bits --)
    {
        H1OUT = 1;
        if((colour & 0b10000000) == 0)
        {
            H1OUT = 0;
        }
        NOP();
        H1OUT = 0;
        colour = colour << 1;
    }
}
