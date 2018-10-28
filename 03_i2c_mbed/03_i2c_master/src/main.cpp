// i2c MASTER

#include "mbed.h"

DigitalOut myled1(PA_5);
DigitalIn mybutton1(PC_13);

#define SDA PB_9
#define SCL PB_8

I2C i2c(SDA, SCL);
 
#define ADDR ((uint8_t)0x01)
Serial pc(SERIAL_TX, SERIAL_RX);

int main() {
    pc.baud(9600);

    Timer name;
    i2c.frequency(100000);

    char cmd[2];
    char data[15];
    char pesan[] = "ini";

    while(1) {
        // if (mybutton1 == 1) myled1 = 0;
        // else    myled1 = 1;
        
        // i2c.write(ADDR, "cmd", 3);
        // i2c.read(ADDR, data, 5);
        

        cmd[0]='0';      
        pc.printf("Request: %s ..",cmd);
        i2c.write(ADDR, cmd, 1);
        i2c.read(ADDR, data, 5);
        pc.printf("Respond: %s \n..", data);
        wait(1);
        cmd[0]='1';
        pc.printf("Request: %s ..",cmd);
        i2c.write(ADDR, cmd, 1);
        i2c.read(ADDR, data, 5);
        pc.printf("Respond: %s \n..", data);
        wait(1);
        cmd[0]='5';
        pc.printf("Request: %s ..",cmd);
        i2c.write(ADDR, cmd, 1);
        i2c.read(ADDR, data, 6);
        pc.printf("Respond: %s \n..", data);
        wait(1);
    }
}