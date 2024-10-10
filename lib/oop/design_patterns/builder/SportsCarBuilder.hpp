#ifndef SPORTSCARBUILDER_H
#define SPORTSCARBUILDER_H

#include "ICarBuilder.hpp"
#include "CarProduct.hpp"

class SportsCarBuilder : public ICarBuilder {
    CarProduct* product;
public:
    SportsCarBuilder()
    {
        this->Reset();
    }

    ~SportsCarBuilder()
    {
        delete this->product;
    }

    void Reset()
    {
        this->product = new CarProduct();
    }

    /*
        All production steps work with the same product instance.
    */

    void SetChassis() const override
    {
        this->product->chassis = "Carbon Fibre Chassis";
    }

    void SetDrivetrain() const override
    {
        this->product->drivetrain = "7-Speed Drivetrain";
    }

    void SetEngine() const override
    {
        this->product->engine = ("V8 Engine");
    }

    void SetWheels() const override
    {
        this->product->wheels = "18-inch Diamond-cut Alloy Wheels";
    }

    void SetSeats() const override
    {
        this->product->seats = "Recaro Seats";
    }

    void SetDashboard() const override
    {
        this->product->dashboard = "Suede Dashboard";
    }

    void SetWiring() const override
    {
        this->product->wiring = "Wiring & Electronics";
    }

    /*
        Implemented Builders can provide their own methods for retrieving results:
        - Thus, various types of builders may create entirely different
          products that don't follow the same interface.
    */
    CarProduct* GetProduct()
    {
        CarProduct* result = this->product;
        this->Reset();
        
        return result;
    }
};

#endif