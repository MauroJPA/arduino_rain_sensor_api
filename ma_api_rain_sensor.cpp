/**
  ******************************************************************************
  * @Company    : Mauro Almeida.
  * @file       : ma_api_rain_sensor.c
  * @author     : Mauro Almeida
  * @version	  : V0.0 
  * @date       : 09/02/2024
  * @brief      : API of resistive rain sensor
  ******************************************************************************
*/ 

/* Includes ------------------------------------------------------------------*/ 
// C language standard library

// Mauro Almeida driver library

// API library
#include "ma_api_rain_sensor.h"

/*******************************************************************************
							HOW TO USE THIS API
********************************************************************************

1. 	First, you should include in your .c file the 
    "ma_api_rain_sensor.h" file.

2.  Call ma_api_rain_sensor_init(DESIRED-PIN) to initialize and setup 
    the sensor parameters.

3.  Call ma_api_rain_sensor_value() to get the sensor raw value.

4.  Call ma_api_rain_sensor_average_percentage_value() to get the sensor 
    average in percentage value.

*******************************************************************************/

/* Private define ------------------------------------------------------------*/
#define ESP_32_ADC_VALUE_MAX 4095 //Esp32 has ADC 10bits = 0 to 4095
/* Private macros ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

typedef struct
{
  uint8_t pin;
} st_rain_sensor_t;

/* Private variables ---------------------------------------------------------*/
st_rain_sensor_t _stRainSensor = {0};

/* Private function prototypes -----------------------------------------------*/  

/* Public objects ------------------------------------------------------------*/

/* Body of private functions -------------------------------------------------*/
/**
  * @Func       : ma_api_rain_sensor_init    
  * @brief      : Init. Rain sensor parameters
  * @pre-cond.  : 
  * @post-cond. : Rain sensor init. and ready to be used
  * @parameters : Sensor pin for physical conection sensor in Hardware
  * @retval     : 
  */
void ma_api_rain_sensor_init(uint8_t in_sensorPin)
{
    _stRainSensor.pin = in_sensorPin;
}

/**
  * @Func       : ma_api_rain_sensor_adc_value    
  * @brief      : Read rain sensor value
  * @pre-cond.  : ma_api_rain_sensor_init
  * @post-cond. : Get rain sensor value
  * @parameters : void
  * @retval     : Rain sensor value in ADC value
  */
uint16_t ma_api_rain_sensor_adc_value(void) 
{
    return analogRead(_stRainSensor.pin);
}

/**
  * @Func       : ma_api_rain_sensor_average_percentage_value    
  * @brief      : Read rain sensor average value
  * @pre-cond.  : ma_api_rain_sensor_init
  * @post-cond. : Get rain sensor average value
  * @parameters : How many times for average
  * @retval     : Rain sensor average value in percentage
  */
uint16_t ma_api_rain_sensor_average_percentage_value(uint8_t in_timesOfAverage) 
{
    in_timesOfAverage = (in_timesOfAverage <= 0) ? 1 : in_timesOfAverage;

    uint32_t sumValueAdc = 0; // Use um tipo de dado maior para evitar overflow
    for(int i = 0; i < in_timesOfAverage; i++)
    {
       sumValueAdc += ma_api_rain_sensor_adc_value(); // Somar o valor do ADC
    }
    uint16_t averageValueAdc = sumValueAdc / in_timesOfAverage; // Calcular a média
    return map(averageValueAdc, ESP_32_ADC_VALUE_MAX, 0, 0, 100);
}
/*****************************END OF FILE**************************************/