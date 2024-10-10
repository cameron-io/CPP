#include "lib/oop/design_patterns/dependency_injection/EnergySource.hpp"
#include "lib/oop/design_patterns/dependency_injection/EnergySourcePetrol.hpp"

int main()
{
    /*
        Base Class is declared ONLY as it requires
        the derived classes to implement 
        its abstract functions
    */
    EnergySource* es;

    /*
        Instantiate & store Derived class in Base
        - for demonstrative purposes
        
        This can be simplified into a single step:
          EnergySource* petrol = new Petrol();
    */
    EnergySourcePetrol* petrol = new EnergySourcePetrol();
    es = petrol;

    /*
        Call Petrol's implementation of virtual function
    */
    es->Get();

    return 0;
}
