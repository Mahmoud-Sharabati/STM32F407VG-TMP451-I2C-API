/*
 * TMP451.h
 *
 *  Created on: May 29, 2023
 *      Author: Mahmoud A. Sharabati
 */

#ifndef __TMP451_H
#define __TMP451_H

#include "stm32f4xx_hal.h"

#define TMP451_SLAVE_ADDRESS                         (0x4E << 1)

/* The TMP451 registers */
#define TMP451_REG_R_LOCAL_TEMP_HB                   0x00
#define TMP451_REG_R_REMOTE_TEMP_HB                  0x01
#define TMP451_REG_R_STATUS                          0x02
#define TMP451_REG_R_CFG                             0x03
#define TMP451_REG_R_CONVERSION_RATE                 0x04
#define TMP451_REG_R_LOCAL_TEMP_LIMIT_H              0x05
#define TMP451_REG_R_LOCAL_TEMP_LIMIT_L              0x06
#define TMP451_REG_R_REMOTE_TEMP_LIMIT_H_HB          0x07
#define TMP451_REG_R_REMOTE_TEMP_LIMIT_L_HB          0x08
#define TMP451_REG_R_REMOTE_TEMP_LB                  0x10
#define TMP451_REG_RW_REMOTE_TEMP_OFFSET_HB          0x11
#define TMP451_REG_RW_REMOTE_TEMP_OFFSET_LB          0x12
#define TMP451_REG_RW_REMOTE_TEMP_LIMIT_H_LB         0x13
#define TMP451_REG_RW_REMOTE_TEMP_LIMIT_L_LB         0x14
#define TMP451_REG_R_LOCAL_TEMP_LB                   0x15
#define TMP451_REG_RW_REMOTE_TEMP_THERM_LIMIT        0x19
#define TMP451_REG_RW_LOCAL_TEMP_THERM_LIMIT         0x20
#define TMP451_REG_RW_THERMO_HYSTERESIS              0x21
#define TMP451_REG_RW_CONSECUTIVE_ALERT              0x22
#define TMP451_REG_RW_M_FACTOR_CORRECTION            0x23
#define TMP451_REG_RW_DIGITAL_FILTER_CTRL            0x24
#define TMP451_REG_R_ID                              0xFE
#define TMP451_REG_W_CFG                             0x09
#define TMP451_REG_W_CONVERSION_RATE                 0x0A
#define TMP451_REG_W_LOCAL_TEMP_LIMIT_H              0x0B
#define TMP451_REG_W_LOCAL_TEMP_LIMIT_L              0x0C
#define TMP451_REG_W_REMOTE_TEMP_LIMIT_H_HB          0x0D
#define TMP451_REG_W_REMOTE_TEMP_LIMIT_L_HB          0x0E
#define TMP451_REG_W_ONE_SHOT                        0x0F

/* defgroup temperature_macro Temperature read macro */
#define TMP451_TEMPERATURE_LOCAL                     0xAA
#define TMP451_TEMPERATURE_REMOTE                    0xBB
#define TMP451_ERROR                                 0x00


/* defgroup dev_id Device ID value */
#define TMP451_DEV_ID                                0x55


/**
 * \defgroup dev_status Device status register
 * \{
 */
#define TMP451_STATUS_BUSY                           0x80
#define TMP451_STATUS_LOCAL_HIGH_TEMP                0x40
#define TMP451_STATUS_LOCAL_LOW_TEMP                 0x20
#define TMP451_STATUS_REMOTE_HIGH_TEMP               0x10
#define TMP451_STATUS_REMOTE_LOW_TEMP                0x08
#define TMP451_STATUS_REMOTE_SENS_OPEN_CIRCUIT       0x04
#define TMP451_STATUS_REMOTE_THERM_TIPPED            0x02
#define TMP451_STATUS_LOCAL_THERM_TIPPED             0x01
/** \} */

/**
 * \defgroup error_code Error Code
 * \{
 */
#define TMP451_OK           0x00
#define TMP451_INIT_ERROR   0xFF
/** \} */

 // ----------------------------------------------- PUBLIC FUNCTION DECLARATIONS

void TMP451_init (I2C_HandleTypeDef* hi2c);

/**
 * @brief Generic write function.
 *
 * @param ctx          Click object.
 * @param reg_adr      Register address.
 * @param write_data   Data to be written.
 *
 * @description This function writes data to the desired register.
 */
void TMP451_generic_write ( uint8_t reg_adr, uint8_t write_data );

/**
 * @brief Generic read function.
 *
 * @param ctx          Click object.
 * @param reg_adr      Register address.
 *
 * @returns Returns read data
 *
 * @description This function reads data from the desired register.
 */
uint8_t TMP451_generic_read ( uint8_t reg_adr );

/**
 * @brief Function for reading temperature.
 *
 * @param ctx          Click object.
 * @param temp_macro   Temperature macro ( TMP451_TEMPERATURE_LOCAL or
 *                                         TMP451_TEMPERATURE_REMOTE ).
 *
 * @returns Returns read data or TMP451_ERROR if temp_macro is wrong
 *
 * @description This function reads data from the local or remote registers.
 */
float TMP451_read_temp ( uint8_t temp_macro );

#endif /* __TMP451_H */
