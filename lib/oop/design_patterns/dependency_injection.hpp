#ifndef DEPENDENCY_INJECTION_H
#define DEPENDENCY_INJECTION_H

#include <iostream>

/*
    This design pattern extends the use of Interfaces
*/
#include "../interface.hpp"

class Car {
    EnergySource *energySource = nullptr;
public:
    /*
        The dependency for a source of gasoline is passed in
        through constructor injection as opposed to
        hard-coded into the class definition.
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
            Abstract away the dependency implementation 
            using polymorphism.
        */
        energySource->Get();
    }
};

#endif