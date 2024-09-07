#include "driverlib.h"
#include "global_var.h"
#include "comm.h"
#include "setup.h"

uint8_t RXData = 90;
uint8_t * TXData = 0;
uint8_t myPayload[32] = {126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126};

void main(void)
{
    //Thread 1: ISR
    init_I2C();

    while(1){
        cmd_process();
    }

}
