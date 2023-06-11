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
1. Modify the Hardware Configuration and Pins using CubeMX software
    This driver use I2C1 with the following pins:
    | I2C1_SCL     | I2C1_SDA   |
    | -------------|:----------:|
    | PB8	         | PB9        |

	#### Notes:																	
	1. You need to modify the name of "Chip-Select pin CS" on your project to be `PCA21125_SPI_CS`.
	2. You must modify the SPI parameters as shown in image below.  
	![SPI_RTC_Config](https://user-images.githubusercontent.com/16566502/217271789-834afec2-b3bb-41af-882d-fa5258ebfe6b.png)  
	3. Other parameters will be automatically modified when generates the code.

2. This Board has an optional LED and Buzzer with the following pins:
   | LED	| Buzzer  |
   |------------|---------|
   | PB0	| PE2	  |

 ### Use PCA21125 Driver instruction
1. Define your RTC_Data `_RTC_R_DATA` and `RTC_Data _RTC_W_DATA` variables to be used to Set and Store the readings.

2. Initialize the PCA21125RTC driver using: `_PCA21125RTC_Init(SPI_HandleTypeDef *hspi, ITStatus INT_Status)`

	Parameters:
   | hspi | INT_Status |
   |------------|--------- |
   | Connected SPI_HandleTypeDef | Status of the RTC INT pin |
   
3. Fill the Current time enum as an initial values. The diver project uses the *_RTC_W_DATA* variable for the initial values.  
4. Set the initial RTC value by using `RTC_SetTime(RTC_Data* _rtc_data)`
5. Get the RTC readings by `PCA21125RTC_GetTime(RTC_Data* _rtc_data)` function. The diver project uses the `_RTC_R_DATA` variable to store reading values into. 

**NOTE: The PCA21125RTC readings in this project can be monitored using the STM32 debugger.**
