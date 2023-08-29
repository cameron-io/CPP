#include <iostream>

#include "lib/oop/design_patterns/factory.hpp"

/*
    The client code works with an instance of a ImplCreator,
    albeit through its base interface.

    As long as the client keeps working with the creator via the
    base interface, you can pass it any creator's subclass.
*/
void ClientCode(const IProductProvider& creator)
{
  std::cout << "Client: I'm not aware of the creator's class.\n"
            << creator.UseProduct() 
            << std::endl;
}

/*
    The Application picks a creator's type depending on 
    the configuration or environment.
*/
int main()
{
  std::cout << "App: Launched with the ImplCreator1.\n";

  IProductProvider* creator = new ProductProvider1();
  ClientCode(*creator);

  std::cout << "App: Launched with the ImplCreator2.\n";

  IProductProvider* creator2 = new ProductProvider2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;

  return 0;
}