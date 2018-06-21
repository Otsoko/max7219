#include <LedControl.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK
 We have only a single MAX72XX.
 */
LedControl lc = LedControl(12, 10, 11, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime1 = 800;

void setup() {
    /*
     The MAX72XX is in power-saving mode on startup,
     we have to do a wakeup call
     */
    lc.shutdown(0, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0, 8);
    /* and clear the display */
    lc.clearDisplay(0);
}

void amz() {
    byte a[8] = {B11111111, B11111111, B00110011, B00110011,
                 B00110011, B00110011, B11111111, B11111111};

    lc.setRow(0, 0, a[0]);
    lc.setRow(0, 1, a[1]);
    lc.setRow(0, 2, a[2]);
    lc.setRow(0, 3, a[3]);
    lc.setRow(0, 4, a[4]);
    lc.setRow(0, 5, a[5]);
    lc.setRow(0, 6, a[6]);
    lc.setRow(0, 7, a[7]);
    delay(delaytime1);

    byte m[8] = {B11111111, B11111111, B00000110, B00001100,
                 B00001100, B00000110, B11111111, B11111111};

    lc.setRow(0, 0, m[0]);
    lc.setRow(0, 1, m[1]);
    lc.setRow(0, 2, m[2]);
    lc.setRow(0, 3, m[3]);
    lc.setRow(0, 4, m[4]);
    lc.setRow(0, 5, m[5]);
    lc.setRow(0, 6, m[6]);
    lc.setRow(0, 7, m[7]);
    delay(delaytime1);

    byte z[8] = {B11000011, B11100011, B11110011, B11111011,
                 B11011111, B11001111, B11000111, B11000011};

    lc.setRow(0, 0, z[0]);
    lc.setRow(0, 1, z[1]);
    lc.setRow(0, 2, z[2]);
    lc.setRow(0, 3, z[3]);
    lc.setRow(0, 4, z[4]);
    lc.setRow(0, 5, z[5]);
    lc.setRow(0, 6, z[6]);
    lc.setRow(0, 7, z[7]);
    delay(delaytime1);

    byte c[8] = {B00001100, B00011110, B00111110, B01111100,
                 B01111100, B00111110, B00011110, B00001100};

    lc.setRow(0, 0, c[0]);
    lc.setRow(0, 1, c[1]);
    lc.setRow(0, 2, c[2]);
    lc.setRow(0, 3, c[3]);
    lc.setRow(0, 4, c[4]);
    lc.setRow(0, 5, c[5]);
    lc.setRow(0, 6, c[6]);
    lc.setRow(0, 7, c[7]);
    delay(delaytime1 * 2);
}

void loop() {
    amz();
}
