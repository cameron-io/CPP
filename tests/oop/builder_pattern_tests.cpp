#include "lib/oop/design_patterns/builder/CarProduct.hpp"
#include "lib/oop/design_patterns/builder/ICarBuilder.hpp"
#include "lib/oop/design_patterns/builder/SportsCarBuilder.hpp"
#include "lib/oop/design_patterns/builder/Pipeline.hpp"
#include <boost/assert.hpp>

void ClientCode()
{
    SportsCarBuilder* builder = new SportsCarBuilder();

    Pipeline pipeline = *new Pipeline(builder);
    
    std::cout << "Minimum rolling chassis:\n"; 
    pipeline.BuildRollingChassisProduct();
    
    CarProduct* p = builder->GetProduct();
    assert(p->CountParts() == 3);
    delete p;

    std::cout << "Standard full featured product:\n"; 
    pipeline.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    
    assert(p->CountParts() == 7);
    delete p;

    /*
        Builder pattern can be used without a Pipeline class.
    */
    std::cout << "Custom product:\n";
    builder->SetChassis();
    builder->SetEngine();

    p = builder->GetProduct();
    assert(p->CountParts() == 2);
    delete p;
}

int main()
{
    ClientCode();
    return 0;    
}
