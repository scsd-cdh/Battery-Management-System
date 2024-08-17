/*
 * comm.h
 *
 *  Created on: Aug. 17, 2024
 *      Author: Amro
 */

#ifndef COMM_H_
#define COMM_H_

typedef enum{
    NONE = 0x00,
    SYSTEM_STATUS = 0x01,
    HEALTH_CHECK = 0x02,
    FLAGS = 0x03,
    POWER_STATUS = 0x04,
    HEATERS_CONTROLLER = 0x05,
    TELECOMMAND_ACKNOWLEDGE = 0x06,
    MAX_CMD_T = 0x07

} cmdID_t;

typedef enum {
    IDLE = 0,
    CMD_RECV,
} cmdSM_t;

static uint8_t payload_sizes[MAX_CMD_T] = {0, 1, 16, 2, 5, 1, 2}; //fix payload sizes

static cmdSM_t mySm = IDLE;
static cmdID_t myCmd = NONE;
static uint8_t myPayload[32] = {0};
static uint8_t myPayloadSize = 0;
static uint8_t counterN = 0;

void cmd_receive(uint8_t data);
void cmd_process(uint8_t cmd, uint8_t* payload,uint8_t payloadSize);



#endif /* COMM_H_ */
