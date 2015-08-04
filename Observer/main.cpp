#include "Observer.h"

int main()
{
    WeatherData *weatherData = new WeatherData();
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(weatherData);
    weatherData->setMeasurements(80, 65, 30.4f);
    weatherData->setMeasurements(82, 70, 29.3f);
    weatherData->setMeasurements(79, 73, 31.8f);
    delete weatherData;
    delete currentDisplay;
    return 0;
}