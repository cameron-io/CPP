#include <boost/assert.hpp>
#include <iostream>
#include <string>

#include "lib/oop/design_patterns/factory.hpp"

/*
    The client code works with an instance of a IBankAccountFactory,
    albeit through its base interface.

    As long as the client keeps working with the creator via the
    base interface, you can pass it any creator's subclass.
*/
void Client(const IBankAccountFactory& bankAccount)
{
    std::cout 
        << "Client: I'm not aware of the creator's sub-class.\n"
        << bankAccount.GetAccountType() 
        << std::endl;
}

/*
    The Application picks a creator's type depending on 
    the configuration or environment.
*/
int main()
{
    std::cout << "App: Launched with the PersonalBankAccountCreator.\n";

    IBankAccountFactory* personalBankAccount = new PersonalBankAccountCreator();
    assert(personalBankAccount->GetAccountType() == "Personal");

    std::cout << "App: Launched with the BusinessBankAccountCreator.\n";

    IBankAccountFactory* businessBankAccount = new BusinessBankAccountCreator();
    Client(*businessBankAccount);
    assert(businessBankAccount->GetAccountType() == "Business");

    delete personalBankAccount;
    delete businessBankAccount;

    return 0;
}