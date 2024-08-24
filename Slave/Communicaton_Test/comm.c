#include "driverlib.h"
#include "comm.h"

extern uint8_t * TXData;

void cmd_receive(uint8_t data) {
    switch(mySm) {
    case IDLE:
        myCmd = (cmdID_t) data;
        mySm = CMD_RECV;
    case CMD_RECV:
        myPayloadSize = payload_sizes[myCmd];
        counterN = 0;
        myPayload[counterN++] = data;
        if (myPayloadSize == counterN) {
            cmd_process(myCmd, myPayload, N);
            mySm = IDLE;
        }
    }
}

uint8_t numbers[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void cmd_process(uint8_t cmd, uint8_t* payload,uint8_t payloadSize) {
    switch(cmd) {
        case SYSTEM_STATUS:
            numbers[0] = 48;
            numbers[1] = 49;
            numbers[2] = 50;
            numbers[3] = 51;
            TXData = numbers;
            break;
        case HEALTH_CHECK:
            break;
        case FLAGS:
            break;
        case POWER_STATUS:
            break;
        case HEATERS_CONTROLLER:
            break;
        case TELECOMMAND_ACKNOWLEDGE:
            break;
    }
}
