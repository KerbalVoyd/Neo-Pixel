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
void neopixel_fill(unsigned char leds, unsigned char red, unsigned char green, unsigned char blue);
unsigned char leds;
unsigned char red, green, blue;
int main(void)
{
    // Configure oscillator and I/O ports. These functions run once at start-up.
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	
    // Code in this while loop runs repeatedly.
    while(1)
	{
        // If SW2 is pressed, make a flashy light pattern
        neopixel_fill(9, 0, 0, 255);
        
        __delay_ms(10);
        // Add code for your Program Analysis and Programming Activities here:

        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

void neopixel_fill(unsigned char leds, unsigned char red, unsigned char green, unsigned char blue)
{
    unsigned char oldRed = red;
    unsigned char oldGreen = green;
    unsigned char oldBlue = blue;
    for(leds; leds != 0; leds --)
    {
        for(unsigned char bits = 8; bits != 0; bits --)
        {
            H1OUT = 1;
            if((green & 0b10000000) == 0)
            {
                H1OUT = 0;
            }
            NOP();
            H1OUT = 0;
            green = green << 1;
        }
        green = oldGreen;
    for(unsigned char bits = 8; bits != 0; bits --)
    {
        H1OUT = 1;
        if((red & 0b10000000) == 0)
        {
            H1OUT = 0;
        }
        NOP();
        H1OUT = 0;
        red = red << 1;
    }
    red = oldRed;
    for(unsigned char bits = 8; bits != 0; bits --)
    {
        H1OUT = 1;
        if((blue & 0b10000000) == 0)
        {
            H1OUT = 0;
        }
        NOP();
        H1OUT = 0;
        blue = blue << 1;
    }
    blue = oldBlue;
    }
}
