#include "driverlib.h"
#include "comm.h"

extern uint8_t TXData;

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

void cmd_process(uint8_t cmd, uint8_t* payload,uint8_t payloadSize) {
    switch(cmd) {
        case SYSTEM_STATUS:
            TXData = 48;
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
