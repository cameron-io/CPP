#ifndef ENERGY_SOURCE_H
#define ENERGY_SOURCE_H

#include <iostream>

/*
    An interface describes the behavior or capabilities of 
    a C++ class without committing to a particular 
    implementation of that class.

    The C++ interfaces are implemented using abstract classes 
    and these abstract classes should not be confused with 
    data abstraction - which is a concept of keeping 
    implementation details separate from associated data.

    A class is made abstract by declaring at least one of 
    its functions as pure virtual function. 
    
    A pure virtual function is specified by placing "= 0" 
    in its declaration.
*/

/*
    Base class

    The purpose of an abstract class (ABC) is to provide an 
    appropriate base class from which other classes can inherit.

    Abstract classes cannot be used to instantiate objects
    and serves only as an interface.

    Attempting to instantiate an object of an abstract class
    causes a compilation error.
*/

class EnergySource {
public:
    // pure virtual function
    virtual void Get() = 0;
    virtual ~EnergySource() = default;
protected:
    int capacity = 100;
};

#endif