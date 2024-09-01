#include "driverlib.h"
#include "global_var.h"
#include "comm.h"
#include "setup.h"

uint8_t RXData = 127;
uint8_t * TXData = 0;

void main(void)
{

    init_I2C();

    while(1){
        cmd_process();
    }

}
