#include <mbed.h>   // include header mbed.h

DigitalOut myled(LED1);   // Inisialisasi pin led yang ada di board stm32f466 nucleo
                          // pin led ada di pin

int main() {

    while(1) {
        myled = 1;    // led nyala
        wait(0.2);    // nyala selama 0.2 detik
        myled = 0;    // led mati
        wait(0.2);    // mati selama 0.2 detik
    }
}
