#ifndef DEPENDENCY_INJECTION_H
#define DEPENDENCY_INJECTION_H

#include <iostream>

class GasolineSource {
public:
    virtual void FuelUp() = 0;
    virtual ~GasolineSource() = default;
};

class GasStation : public GasolineSource {
public:
    virtual void FuelUp();
};

class FuelCan : public GasolineSource {
public:
    virtual void FuelUp();
};

class Car {
    GasolineSource *gasolineService = nullptr;
public:
    // The dependency for a source of gasoline is passed in
    // through constructor injection
    // as opposed to hard-coded into the class definition.
    Car(GasolineSource *service)
    : gasolineService(service) {
        // If the dependency was not defined, throw an exception.
        if(gasolineService == nullptr){
            throw std::invalid_argument("service must not be null");
        }
    }
    void getGasoline();
};

#endif