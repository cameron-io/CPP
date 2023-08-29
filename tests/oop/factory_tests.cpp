#include <iostream>

#include "lib/oop/design_patterns/factory.hpp"

/*
    The client code works with an instance of a ImplCreator,
    albeit through its base interface.

    As long as the client keeps working with the creator via the
    base interface, you can pass it any creator's subclass.
*/
void ClientCode(const Creator& creator)
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

  Creator* creator = new ImplCreator1();
  ClientCode(*creator);

  std::cout << "App: Launched with the ImplCreator2.\n";

  Creator* creator2 = new ImplCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;

  return 0;
}