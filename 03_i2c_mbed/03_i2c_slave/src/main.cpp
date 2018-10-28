// i2c Slave

#include "mbed.h"

#define SDA PB_9
#define SCL PB_8
#define ADDR 0x01

AnalogIn ain(PA_0);
I2CSlave slave(SDA, SCL);
Serial pc(SERIAL_TX, SERIAL_RX);
 
// DigitalOut myled1(PA_5);
// DigitalIn mybutton1(PC_13);
 


int main()
{
    pc.baud(9600);

    char buf[10];
    char msg[] = "Slave!";
    uint8_t data;
    
    slave.frequency(100000);
    int receive;
    slave.address(ADDR);
    while(1) {
        // if (mybutton1 == 1) myled1 = 0;
        // else    myled1 = 1;

        receive = slave.receive();
        // pc.printf("%d\n", receive);
        // slave.write(msg, strlen(msg) + 1); // Includes null char

        // tambahan untuk ngolongtech.net
       switch (receive) {
            case I2CSlave::ReadAddressed:
                // slave.write(msg, strlen(msg) + 1); // Includes null char        
                if(data == 0) {
                    slave.write("zero", 5);
                }
                else if(data == 1) {
                    slave.write("once", 5);
                }
                else {
                    slave.write("Error", 6);
                }
                break;
            case I2CSlave::WriteGeneral:
                // slave.read(buf, 10);
                // pc.printf("Read G: %s\n", buf);
                break;
            case I2CSlave::WriteAddressed:
                // slave.read(buf, 10);
                // pc.printf("Read A: %s\n", buf);
                slave.read(buf, 1);
                data = atoi(buf);
                break;
       }
       for(int i = 0; i < 10; i++) buf[i] = 0;    // Clear buffer
    }
}
