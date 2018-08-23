#include <mbed.h>

DigitalIn tombol(USER_BUTTON);
DigitalOut myled(LED1);

int main() {
  while(1) {
    if (tombol == 0) { // Jika tombol di tekan
      myled = 1; // led nyala
    }
    else {  // jika tidak di tekan
      myled = 0; // led mati
    }
  }
}
