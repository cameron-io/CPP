#ifndef INTERFACE_H
#define INTERFACE_H

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

/*
    Derived classes

    Thus, if a subclass of an ABC needs to be instantiated,
    it has to implement each of the virtual functions.
    
    This means that it supports the interface declared 
    by the ABC.

    Failure to override a pure virtual function in a derived
    class, then attempting to instantiate objects of that class,
    results in a compilation error.
*/

class Petrol : public EnergySource {
public:
    virtual void Get()
    {
        std::cout << "Getting petrol" << std::endl;
        this->capacity--;
    }
};

class Battery : public EnergySource {
public:
    virtual void Get()
    {
        std::cout << "Recharging battery" << std::endl;
        this->capacity--;
    }
};

#endif