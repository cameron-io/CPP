#include "lib/oop/dependency_injection.hpp"

int dep_injection_test()
{
    GasolineSource *stationService = new GasStation();
    GasolineSource *canService = new FuelCan();

    // racecar is independent from the implementation of the fuel service.
    // a gas station service is injected.
    Car racecar(stationService);
    racecar.getGasoline();

    // dune buggy is independent from the implementation of the fuel service.
    // a fuel can service is injected.
    Car duneBuggy(canService);
    duneBuggy.getGasoline();

    delete stationService;
    delete canService;
    
    return 0;
}

int main()
{
    return dep_injection_test();
}