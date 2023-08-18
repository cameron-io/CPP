#include "dependency_injection.hpp"

void GasStation::FuelUp()
{
    std::cout << "Pumping gas at gas station" << std::endl;
}

void FuelCan::FuelUp()
{
    std::cout << "Pumping gas from fuel can" << std::endl;
}

void Car::getGasoline()
{
    std::cout << "Car needs more gasoline!" << std::endl;
    // Abstract away the dependency implementation with polymorphism.
    gasolineService->FuelUp();
}
