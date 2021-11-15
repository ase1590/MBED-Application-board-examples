//Simple serial printer
// with output going from the normal usb connection on the controller
#include "mbed.h"

// Specify different pins to test printing on UART other than the console UART.
#define TARGET_TX_PIN                                                     USBTX
#define TARGET_RX_PIN                                                     USBRX

// Create a BufferedSerial object to be used by the system I/O retarget code.
static BufferedSerial serial_port(TARGET_TX_PIN, TARGET_RX_PIN, 9600);

FileHandle *mbed::mbed_override_console(int fd)
{
    return &serial_port;
}

int main(void)
{
    // print to the console using the `serial_port` object.

    while (1)
    {
            printf(
        "Mbed OS version %d.%d.%d\n",
        MBED_MAJOR_VERSION,
        MBED_MINOR_VERSION,
        MBED_PATCH_VERSION
    );
        printf("\nHello world\n");
        serial_port.sync(); //flush the serial before sleep
        thread_sleep_for(1000);
    }
    
}