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
    Car(GasolineSource *service);
    void getGasoline();
};

#endif