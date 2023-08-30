#ifndef BUILDER_PATTERN_H
#define BUILDER_PATTERN_H

#include <iostream>
#include <string>
#include <vector>

/*
    Commonly, the Builder pattern is only used when the
    classes are complex & require extensive configuration
*/

/*
    Unlike Factory & other patterns, the builders
    can produce unrelated products.

    Thus, the results from builders may not follow the
    same interface
*/
class CarProduct{
public:
    std::vector<std::string> parts;

    void ListParts() const
    {
        std::cout << "Product materials:\n";
        
        for (int i = 0; i < parts.size(); i++) {
            std::cout << "-> " << parts[i] << "\n";
        }

        std::cout << "\n" << std::endl;
    }
};


/*
    The Builder interface specifies methods for creating the
    different parts of the Product objects.
*/
class IBuilder{
public:
    virtual ~IBuilder() = default;
    virtual void ProduceChassis() const = 0;
    virtual void ProduceDrivetrain() const = 0;
    virtual void ProduceEngine() const = 0;
    virtual void ProduceWheels() const = 0;
    virtual void ProduceSeats() const = 0;
    virtual void ProduceDashboard() const = 0;
    virtual void ProduceWiring() const = 0;
};


class SportsCarBuilder : public IBuilder {
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

    void ProduceChassis() const override
    {
        this->product->parts.push_back("Carbon Fibre Chassis");
    }

    void ProduceDrivetrain() const override
    {
        this->product->parts.push_back("7-Speed Drivetrain");
    }

    void ProduceEngine() const override
    {
        this->product->parts.push_back("V8 Engine");
    }

    void ProduceWheels() const override
    {
        this->product->parts.push_back("18-inch Diamond-cut Alloy Wheels");
    }

    void ProduceSeats() const override
    {
        this->product->parts.push_back("Recaro Seats");
    }

    void ProduceDashboard() const override
    {
        this->product->parts.push_back("Suede Dashboard");
    }

    void ProduceWiring() const override
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


/*
    The builders may be abstracted into a Pipeline, which is
    responsible for executing the build steps for a specific
    product instance in its required sequence.
*/
class Pipeline {
    IBuilder* builder = nullptr;
public:
    Pipeline(IBuilder* custom_builder)
        : builder(custom_builder)
    {
        if (builder == nullptr) {
            throw std::invalid_argument("builder must not be null");
        }
    }

    void BuildRollingChassisProduct()
    {
        this->builder->ProduceChassis();
        this->builder->ProduceSeats();
        this->builder->ProduceWheels();
    }

    void BuildFullFeaturedProduct()
    {
        this->builder->ProduceChassis();
        this->builder->ProduceDrivetrain();
        this->builder->ProduceEngine();
        this->builder->ProduceWheels();
        this->builder->ProduceSeats();
        this->builder->ProduceDashboard();
        this->builder->ProduceWiring();
    }
};

#endif