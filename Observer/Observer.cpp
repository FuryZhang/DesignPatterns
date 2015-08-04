#include "Observer.h"
#include <iostream>

void WeatherData::registerObserver(Observer *o)
{
    observers_.push_back(o);
}

void WeatherData::removeObserver(Observer *o)
{
    observers_.remove(o);
}

void WeatherData::notifyObservers()
{
    for (auto it = observers_.begin(); it != observers_.end(); ++it)
    {
        (*it)->update(temperature_, humidity_, pressure_);
    }
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}

void WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
    this->temperature_ = temperature;
    this->humidity_ = humidity;
    this->pressure_ = pressure;
    measurementsChanged();
}

void CurrentConditionsDisplay::update(float temperature, float humidity, float pressure)
{
    this->temperature_ = temperature;
    this->humidity_ = humidity;
    display();
}

void CurrentConditionsDisplay::display()
{
    std::cout << "Current conditions:" << temperature_
        << "F degrees and " << humidity_ << "% humidity" << std::endl;
}
