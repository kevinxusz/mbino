/* mbino Example Program based on
 *
 * https://os.mbed.com/media/uploads/robt/mbed_course_notes_-_serial_spi.pdf
 *
 * These course notes are written by R.Toulson (Anglia Ruskin
 * University) and T.Wilmshurst (University of Derby). (c) ARM 2012
 *
 * These course notes accompany the textbook "Fast and effective
 * embedded system design: Applying the ARM mbed"
 */
#include "mbed.h"

SPI acc(D11, D12, D13);             // setup SPI interface on pins 11,12,13
DigitalOut cs(D10);                 // use pin 10 as chip select
char buffer[6];                     // raw data array type char
signed short data[3];               // acc data is signed 16 bit from -32,768 to +32,767
float x, y, z;                      // floating point data

int main() {
    cs=1;
    acc.format(8,3);                // 8 bit data, Mode 3
    acc.frequency(2000000);         // 2MHz clock rate
    cs=0;
    acc.write(0x31);                // data format register
    acc.write(0x0B);                // format +/-16g, 0.004g/LSB
    cs=1;
    cs=0;
    acc.write(0x2D);                // power ctrl register
    acc.write(0x08);                // measure mode
    cs=1;
    while (1) {                     // infinite loop
        wait(0.2);
        cs=0;
        acc.write(0x80|0x40|0x32);                // RW bit high, MB bit high, plus address
        for (int i= 0;i<=5;i++) {
            buffer[i]=acc.write(0x00);            // read back 6 data bytes
        }
        cs=1;
        data[0] = buffer[1]<<8 | buffer[0];       // combine MSB and LSB
        data[1] = buffer[3]<<8 | buffer[2];
        data[2] = buffer[5]<<8 | buffer[4];
        x=0.004*data[0]; y=0.004*data[1]; z=0.004*data[2];      // convert to floating point
        printf("x = %+1.2fg\t y = %+1.2fg\t z = %+1.2fg\n\r", x,y,z); //print to screen
    }
}
