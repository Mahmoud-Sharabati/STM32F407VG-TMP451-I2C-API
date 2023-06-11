/*
 * TMP451.c
 *
 *  Created on: May 29, 2023
 *      Author: Mahmoud A. Sharabati
 */
#include "TMP451.h"

// ------------------------------------------------------------- PRIVATE MACROS

#define TMP451_LB_RESOLUTION                              0.0625
#define TMP451_LB_SHIFT                                   4
#define TMP451_WRITE_SIZE                                 2
#define TMP451_READ_SIZE                                  1

// ------------------------------------------------ PUBLIC FUNCTION DEFINITIONS
I2C_HandleTypeDef* TMP451_I2C;

void TMP451_init (I2C_HandleTypeDef* hi2c)
{
	TMP451_I2C = hi2c;

	if (HAL_I2C_IsDeviceReady(TMP451_I2C, TMP451_SLAVE_ADDRESS, 1, 10) != HAL_OK)  {
		Error_Handler();
	}
}

void TMP451_generic_write ( uint8_t reg_adr, uint8_t write_data )
{
    uint8_t tx_buf[ TMP451_WRITE_SIZE ];

    tx_buf[ 0 ] = reg_adr;
    tx_buf[ 1 ] = write_data;

    HAL_I2C_Master_Transmit(TMP451_I2C,TMP451_SLAVE_ADDRESS,tx_buf,TMP451_WRITE_SIZE, 10);
}

uint8_t TMP451_generic_read ( uint8_t reg_adr )
{
    uint8_t tx_buf[ 1 ];
    uint8_t temp_data;

    tx_buf [ 0 ] = reg_adr;

//    HAL_I2C_Master_Transmit(TMP451_I2C, TMP451_SLAVE_ADDRESS, tx_buf, TMP451_WRITE_SIZE, 10);
    if (HAL_I2C_Master_Transmit(TMP451_I2C, TMP451_SLAVE_ADDRESS, tx_buf, TMP451_WRITE_SIZE, 10) != HAL_OK)	{
    	Error_Handler();
    }
    else {
    	HAL_I2C_Master_Receive(TMP451_I2C, TMP451_SLAVE_ADDRESS, &temp_data, TMP451_READ_SIZE, 10);
    }
    //    i2c_master_write_then_read( &ctx->i2c, tx_buf, 1, &temp_data, TMP451_READ_SIZE );

    return temp_data;
}

float TMP451_read_temp ( uint8_t temp_macro )
{
    float ret_data;
    uint8_t tmp;

    switch ( temp_macro )
    {
        case TMP451_TEMPERATURE_LOCAL:
        {
            tmp = TMP451_generic_read( TMP451_REG_R_LOCAL_TEMP_HB );
            ret_data = tmp;
            tmp = TMP451_generic_read( TMP451_REG_R_LOCAL_TEMP_LB );
            tmp >>= TMP451_LB_SHIFT;
            ret_data += tmp * TMP451_LB_RESOLUTION;
            return ret_data;
        }

        case TMP451_TEMPERATURE_REMOTE:
        {
            tmp = TMP451_generic_read( TMP451_REG_R_REMOTE_TEMP_HB );
            ret_data = tmp;
            tmp = TMP451_generic_read( TMP451_REG_R_REMOTE_TEMP_LB );
            tmp >>= TMP451_LB_SHIFT;
            ret_data += tmp * TMP451_LB_RESOLUTION;
            return ret_data;
        }

        default:
        {
            return TMP451_ERROR;
        }
    }
}

// ------------------------------------------------------------------------- END
