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
        this->product->parts.push_back("Carbon Fibre Chassis");
    }

    void SetDrivetrain() const override
    {
        this->product->parts.push_back("7-Speed Drivetrain");
    }

    void SetEngine() const override
    {
        this->product->parts.push_back("V8 Engine");
    }

    void SetWheels() const override
    {
        this->product->parts.push_back("18-inch Diamond-cut Alloy Wheels");
    }

    void SetSeats() const override
    {
        this->product->parts.push_back("Recaro Seats");
    }

    void SetDashboard() const override
    {
        this->product->parts.push_back("Suede Dashboard");
    }

    void SetWiring() const override
    {
        this->product->parts.push_back("Wiring & Electronics");
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