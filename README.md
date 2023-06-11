# STM32F407VG-TMP451-I2C-API
This repository contains the source code and documentation for interfacing the TMP451 I2C remote and local temperature sensor with the STM32F407 microcontroller.

## Overview
The TMP451 is a high-accuracy, low-power remote temperature sensor monitor with a built-in local temperature sensor. The remote temperature sensors are typically low-cost discrete NPN or PNP transistors, or substrate thermal transistors or diodes that are integral parts of microprocessors, microcontrollers, or FPGAs. The STM32F407 is a popular high-performance microcontroller from STMicroelectronics, with a wide range of peripherals and features. This project demonstrates how to interface the PCA21125 RTC with the STM32F407 using the SPI peripheral, to accurately keep track of the current date and time.

## Requirements
* STM32F407 development board
* TMP451 or TMP451-Q temperature sensor
* STM32 development environment (STM32CubeIDE)
* TMP451 datasheet and STM32F407 datasheet
* The STM32CubeMX software, available [here](https://www.st.com/en/development-tools/stm32cubemx.html).

## Installation
1. Clone the repository:
git clone [here](https://github.com/Mahmoud-Sharabati/STM32F407VG-TMP451-I2C-API.git).
2. Import the project into STM32CubeMX by selecting File > Import > C/C++ > Existing Code as Makefile Project.
3. Configure the project in STM32CubeMX according to your hardware setup.
4. Generate the code and open the project in your preferred development environment.
5. Build and upload the code to your device.

**OR: you can use this example by modifying the I2C Handler depending on your connection as follow.**

## Usage

### Before using TMP451 I2C Driver
1. Modify the Hardware Configuration and Pins using CubeMX software.
    This driver use I2C1 with the following pins:
    | I2C1_SCL     | I2C1_SDA   |
    | -------------|:----------:|
    | PB8	   | PB9        |

#### Notes:																	
1. You must modify the I2C parameters as shown in image below.  
	1. (![I2C_Config][image](https://github.com/Mahmoud-Sharabati/STM32F407VG-TMP451-I2C-API/assets/16566502/e24d9676-ac2c-4d30-87a3-01d070e51352))
	2. Other parameters will be automatically modified when generates the code.

2. This Board has an optional GPIO Buzzer with the following pin:
   | BUZZER  |
   |---------|
   | PA3     |

 ### Use TMP451 Driver instruction
1. Define your `read_data` variable to be used to Set and Store the readings.

2. Initialize the TMP451 driver using: `TMP451_init (I2C_HandleTypeDef* hi2c)`

	Parameters:
   | hi2c |
   |------|
   | Connected I2C_HandleTypeDef |
   
3. Get the temperature readings by `TMP451_read_temp ( uint8_t temp_macro )` function. The diver project uses the `read_data` variable to store reading values into.
		temp_macro can be:
   | TMP451_TEMPERATURE_LOCAL | TMP451_TEMPERATURE_REMOTE |
   |------|:----------:|
   | Local temperature | Remote temperature |
   
**NOTE: The TMP451 readings in this project can be monitored using the STM32 debugger.**

## Credits
This project was built using the [mikrosdk_click_v2](https://github.com/MikroElektronika/mikrosdk_click_v2/tree/master/clicks/thermo17) library developed by [MikroElektronika](https://www.mikroe.com/). The mikrosdk_click_v2 library provides a comprehensive set of drivers and examples for various click boards, including the Thermo 17 click.

## License
This driver is licensed under the MIT License. See the LICENSE file for details.
