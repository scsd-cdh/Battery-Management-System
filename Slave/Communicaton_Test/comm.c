#include "driverlib.h"
#include "global_var.h"
#include "comm.h"
#include "setup.h"

uint8_t data;

void cmd_receive(uint8_t data) {
    switch(cmdStatus) {
    case AWAITING:
        myCmd = (cmdID_t) data;
        myPayloadSize = payload_sizes[myCmd];

        if (myPayloadSize==0){
            cmdStatus = AWAITING;
        }else{
            cmdStatus = RECEIVED;
        }

        break;
    case RECEIVED:
        myPayload[counterN++] = data;
        if (myPayloadSize == counterN) {
            counterN = 0;
            cmdStatus = AWAITING;
        }
        break;
    }
}

uint8_t numbers[32] = {60,61,62,63,64,65,66,67,68,69,70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int blow = 0;

void cmd_process() {
    switch(myCmd) {
        case IDLE:
            if (blow >3){
                GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

                GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
            }
            blow++;
            resumeI2CInterrupts();
            break;
        case SYSTEM_STATUS:
            numbers[0] = 48;
            numbers[1] = 49;
            numbers[2] = 50;
            numbers[3] = 51;
            TXData = numbers;
//            blow++;

            myCmd = IDLE;
            break;
        case HEALTH_CHECK:

            myCmd = IDLE;
            break;
        case FLAGS:

            myCmd = IDLE;
            break;
        case POWER_STATUS:

            myCmd = IDLE;
            break;
        case HEATERS_CONTROLLER:

            myCmd = IDLE;
            break;
        case TELECOMMAND_ACKNOWLEDGE:

            myCmd = IDLE;
            break;
    }
}
