#include "lib/oop/design_patterns/dependency_injection.hpp"

int dependency_injection_test()
{
    EnergySource *petrolSource = new Petrol();
    EnergySource *batterySource = new Battery();

    // each car is independent from the 
    // implementation of the energy source.
    
    // petrol source is injected.
    Car mclaren_f1(petrolSource);
    mclaren_f1.getEnergy();

    // battery source is injected.
    Car formula_e(batterySource);
    formula_e.getEnergy();

    delete petrolSource;
    delete batterySource;
    
    return 0;
}

int main()
{
    return dependency_injection_test();
}