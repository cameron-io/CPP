#include "lib/oop/design_patterns/dependency_injection/Car.hpp"
#include "lib/oop/design_patterns/dependency_injection/EnergySource.hpp"
#include "lib/oop/design_patterns/dependency_injection/EnergySourceBattery.hpp"
#include "lib/oop/design_patterns/dependency_injection/EnergySourcePetrol.hpp"

int dependency_injection_test()
{
    EnergySource *petrolSource = new EnergySourcePetrol();
    EnergySource *batterySource = new EnergySourceBattery();

    // each car is independent from the 
    // implementation of the energy source.
    
    // petrol source is injected.
    Car mclaren_f1(petrolSource);
    mclaren_f1.GetEnergy();

    // battery source is injected.
    Car formula_e(batterySource);
    formula_e.GetEnergy();

    delete petrolSource;
    delete batterySource;
    
    return 0;
}

int main()
{
    return dependency_injection_test();
}