/**
    ******************************************************************************
    * @Company    : Mauro Almeida.
    * @file       : ma_rain_sensor.h
    * @author     : Mauro Almeida
    * @version	  : V0.0 
    * @date       : 09/02/2024
    * @brief      : Header file of resistive rain sensor
    ******************************************************************************
*/ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MA_API_RAIN_SENSOR_H
#define __MA_API_RAIN_SENSOR_H

/* Includes ------------------------------------------------------------------*/  
#include <Arduino.h>
/* Define --------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Public objects ------------------------------------------------------------*/
extern void     ma_api_rain_sensor_init                     (uint8_t in_sensorPin);     //Initialize rain sensor configs
extern uint16_t ma_api_rain_sensor_adc_value                (void);                     //Read rain sensor raw value
extern uint16_t ma_api_rain_sensor_average_percentage_value (uint8_t in_timesOfAverage);//Get rain sensor average value in percantage

#endif /* __MA_API_RAIN_SENSOR_H */
/*****************************END OF FILE**************************************/