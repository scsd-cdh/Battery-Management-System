/*
 * comm.h
 *
 *  Created on: Aug. 17, 2024
 *      Author: Amro
 */

#ifndef COMM_H_
#define COMM_H_

typedef enum{
    IDLE = 0x00,
    SYSTEM_STATUS = 0x01,
    HEALTH_CHECK = 0x02,
    FLAGS = 0x03,
    POWER_STATUS = 0x04,
    HEATERS_CONTROLLER = 0x05,
    TELECOMMAND_ACKNOWLEDGE = 0x06,
    MAX_CMD_T = 0x07

} cmdID_t;

typedef enum{
    AWAITING = 0,
    RECEIVED = 1
} cmdStatus_t;

static uint8_t payload_sizes[MAX_CMD_T] = {0, 0, 16, 2, 5, 1, 2}; //fix payload sizes
static cmdStatus_t cmdStatus = AWAITING;
static cmdID_t myCmd = IDLE;
static uint8_t myPayload[32] = {0};
static uint8_t myPayloadSize = 0;
static uint8_t counterN = 0;

void cmd_receive(uint8_t data);
void cmd_process();



#endif /* COMM_H_ */
