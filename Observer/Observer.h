#include <list>

class Observer;

class Subject
{
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObservers() = 0;

protected:
    std::list<Observer*> observers_;
};

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
};

class DisplayElement
{
public:
    virtual void display() = 0;
};


class WeatherData : public Subject
{
public:
    void registerObserver(Observer *o);
    void removeObserver(Observer *o);
    void notifyObservers();
    void measurementsChanged();
    void setMeasurements(float temperature, float humidity, float pressure);

    // ...
    // other methods

private:
    float temperature_;
    float humidity_;
    float pressure_;
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    CurrentConditionsDisplay(Subject *wd) : weatherData_(wd)
    {
        weatherData_->registerObserver(this);
    }

    void update(float temperature, float humidity, float pressure);
    void display();

private:
    float temperature_;
    float humidity_;
    Subject *weatherData_;
};