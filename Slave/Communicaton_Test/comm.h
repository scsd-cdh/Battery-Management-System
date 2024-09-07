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
    HEALTH_CHECK = 0x22,
    FLAGS = 0x03,
    POWER_STATUS = 0x04,
    HEATERS_CONTROLLER = 0x05,
    TELECOMMAND_ACKNOWLEDGE = 0x06,

} cmdID_t;

#define MAX_CMD_T 0x07

typedef enum{
    AWAITING = 0,
    RECEIVING = 1
} cmdStatus_t;

static uint8_t payload_sizes[MAX_CMD_T] = {0, 0, 1, 2, 5, 1, 2}; //fix payload sizes
static cmdStatus_t cmdStatus = AWAITING;
static cmdID_t current_Statemachine = IDLE;

void cmd_receive();
void cmd_process();



#endif /* COMM_H_ */
