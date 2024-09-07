#include "driverlib.h"
#include "global_var.h"
#include "comm.h"
#include "setup.h"

uint8_t data;

void cmd_receive() {

    current_Statemachine = (cmdID_t) myPayload[0];
}

uint8_t numbers[32] = {60,61,62,63,64,65,66,67,68,69,70,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void cmd_process() {

    switch(current_Statemachine) {
        case IDLE:
            resumeI2CInterrupts();
            break;
        case SYSTEM_STATUS:
            numbers[0] = 48;
            numbers[1] = 49;
            numbers[2] = 50;
            numbers[3] = 51;
            TXData = numbers;

            current_Statemachine = IDLE;
            break;
        case HEALTH_CHECK:

            TXData = myPayload;
//            TXData++;

            current_Statemachine = IDLE;
            break;
        case FLAGS:

            current_Statemachine = IDLE;
            break;
        case POWER_STATUS:

            current_Statemachine = IDLE;
            break;
        case HEATERS_CONTROLLER:

            current_Statemachine = IDLE;
            break;
        case TELECOMMAND_ACKNOWLEDGE:

            current_Statemachine = IDLE;
            break;
    }
}
