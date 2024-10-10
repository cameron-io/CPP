#ifndef ICARBUILDER_H
#define ICARBUILDER_H

/*
    Commonly, the Builder pattern is only used when the
    classes are complex & require extensive configuration
*/

/*
    The Builder interface specifies methods for creating the
    different parts of the Product objects.
*/
class ICarBuilder{
public:
    virtual ~ICarBuilder() = default;
    virtual void SetChassis() const = 0;
    virtual void SetDrivetrain() const = 0;
    virtual void SetEngine() const = 0;
    virtual void SetWheels() const = 0;
    virtual void SetSeats() const = 0;
    virtual void SetDashboard() const = 0;
    virtual void SetWiring() const = 0;
};

#endif