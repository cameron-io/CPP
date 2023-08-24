#ifndef DEPENDENCY_INJECTION_H
#define DEPENDENCY_INJECTION_H

#include <iostream>

/*
    This design pattern extends the use of Interfaces
*/
#include "../interface.hpp"

class Car {
    /*
        This represents the base class interface for 
        the required dependency implementation
    */
    EnergySource *energySource = nullptr;
public:
    /*
        The derived class dependency for the source of energy 
        is passed in through constructor injection:
        - as opposed to hard-coded into the class definition.
    */
    Car(EnergySource *service)
        : energySource(service)
    {
        // If the dependency was not defined, throw an exception.
        if (energySource == nullptr) {
            throw std::invalid_argument("service must not be null");
        }
    }
    void getEnergy()
    {
        std::cout << "Car is pulling in to service station!" << std::endl;
        /*
            Call the interface dependency's derived 
            implementation of the virtual function,
            abstracting away the implementation
        */
        energySource->Get();
    }
};

#endif