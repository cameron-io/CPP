#ifndef PIPELINE_H
#define PIPELINE_H

#include <iostream>
#include "ICarBuilder.hpp"

/*
    The builders may be abstracted into a Pipeline, which is
    responsible for executing the build steps for a specific
    product instance in its required sequence.
*/
class Pipeline {
    ICarBuilder* builder = nullptr;
public:
    Pipeline(ICarBuilder* car_builder)
        : builder(car_builder)
    {
        if (builder == nullptr) {
            throw std::invalid_argument("builder must not be null");
        }
    }

    void BuildRollingChassisProduct()
    {
        this->builder->SetChassis();
        this->builder->SetSeats();
        this->builder->SetWheels();
    }

    void BuildFullFeaturedProduct()
    {
        this->builder->SetChassis();
        this->builder->SetDrivetrain();
        this->builder->SetEngine();
        this->builder->SetWheels();
        this->builder->SetSeats();
        this->builder->SetDashboard();
        this->builder->SetWiring();
    }
};

#endif