#include "lib/oop/design_patterns/builder/CarProduct.hpp"
#include "lib/oop/design_patterns/builder/ICarBuilder.hpp"
#include "lib/oop/design_patterns/builder/SportsCarBuilder.hpp"
#include "lib/oop/design_patterns/builder/Pipeline.hpp"

void ClientCode()
{
    SportsCarBuilder* builder = new SportsCarBuilder();

    Pipeline pipeline = *new Pipeline(builder);
    
    std::cout << "Minimum rolling chassis:\n"; 
    pipeline.BuildRollingChassisProduct();
    
    CarProduct* p = builder->GetProduct();
    if (p->CountParts() != 3)
        throw new std::logic_error(
            "assertion failure");
    delete p;

    std::cout << "Standard full featured product:\n"; 
    pipeline.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    
    if (p->CountParts() != 7)
        throw new std::logic_error(
            "assertion failure");
    delete p;

    /*
        Builder pattern can be used without a Pipeline class.
    */
    std::cout << "Custom product:\n";
    builder->SetChassis();
    builder->SetEngine();

    p = builder->GetProduct();
    if (p->CountParts() != 2)
        throw new std::logic_error(
            "assertion failure");
    delete p;
}

int main()
{
    ClientCode();
    return 0;    
}
