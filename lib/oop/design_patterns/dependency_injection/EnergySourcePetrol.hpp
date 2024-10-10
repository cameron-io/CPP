#ifndef ENERGY_SOURCE_PETROL_H
#define ENERGY_SOURCE_PETROL_H

#include <iostream>
#include "EnergySource.hpp"

/*
    Derived class of EnergySource

    Thus, if a subclass of an ABC needs to be instantiated,
    it has to implement each of the virtual functions.
    
    This means that it supports the interface declared 
    by the ABC.

    Failure to override a pure virtual function in a derived
    class, then attempting to instantiate objects of that class,
    results in a compilation error.
*/

class EnergySourcePetrol : public EnergySource {
public:
    virtual void Get()
    {
        std::cout << "Getting petrol" << std::endl;
        this->capacity--;
    }
};

#endif