#include "dependency_injection.hpp"

/*
    The dependency for a source of gasoline is passed in
    through constructor injection as opposed to
    hard-coded into the class definition.
*/
Car::Car(GasolineSource *service) : gasolineService(service)
{
    // If the dependency was not defined, throw an exception.
    if (gasolineService == nullptr) {
        throw std::invalid_argument("service must not be null");
    }
}

void Car::getGasoline()
{
    std::cout << "Car needs more gasoline!" << std::endl;
    /*
        Abstract away the dependency implementation 
        using polymorphism.
    */
    gasolineService->FuelUp();
}

void GasStation::FuelUp()
{
    std::cout << "Pumping gas at gas station" << std::endl;
}

void FuelCan::FuelUp()
{
    std::cout << "Pumping gas from fuel can" << std::endl;
}
