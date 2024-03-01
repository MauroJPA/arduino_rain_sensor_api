#include "ma_api_rain_sensor.h"

#define DF_SENSOR_PIN 35
#define DF_SENSOR_TIMES_FOR_AVERAGE 6

void setup() 
{
    // Initialize rain sensor with pin 5
    ma_api_rain_sensor_init(DF_SENSOR_PIN);
}

void loop()
{
    // Read the raw ADC value of the rain sensor
    uint16_t rawValue = ma_api_rain_sensor_adc_value();
    printf("Raw ADC value: %d\n", rawValue);

    // Read the average percentage value of the rain sensor based on 6 readings
    uint16_t averagePercentage = ma_api_rain_sensor_average_percentage_value(DF_SENSOR_TIMES_FOR_AVERAGE);
    printf("Average percentage value: %d%%\n", averagePercentage);

    delay(1000);
}