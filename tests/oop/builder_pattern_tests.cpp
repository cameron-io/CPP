#include "lib/oop/design_patterns/builder_pattern.hpp"

void ClientCode()
{
    SportsCarBuilder* builder = new SportsCarBuilder();

    Pipeline pipeline = *new Pipeline(builder);
    
    std::cout << "Minimum rolling chassis:\n"; 
    pipeline.BuildRollingChassisProduct();
    
    CarProduct* p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Standard full featured product:\n"; 
    pipeline.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    /*
        Builder pattern can be used without a Pipeline class.
    */
    std::cout << "Custom product:\n";
    builder->ProduceChassis();
    builder->ProduceEngine();

    p = builder->GetProduct();
    p->ListParts();
    delete p;
}

int main()
{
    ClientCode();
    return 0;    
}
