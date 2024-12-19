#include "lib/oop/design_patterns/factory/domain/IAccount.hpp"
#include "lib/oop/design_patterns/factory/domain/IAccountFactory.hpp"
#include "lib/oop/design_patterns/factory/service/AccountPersonalCreator.hpp"
#include "lib/oop/design_patterns/factory/service/AccountBusinessCreator.hpp"
#include <boost/assert.hpp>
#include <iostream>
#include <string>


/*
    The client code works with an instance of a IAccountFactory,
    albeit through its base interface.

    As long as the client keeps working with the creator via the
    base interface, you can pass it any creator's subclass.
*/
void Client(const IAccountFactory& Account)
{
    std::cout 
        << "Client: I'm not aware of the creator's sub-class.\n"
        << Account.GetAccountType() 
        << std::endl;
}

/*
    The Application picks a creator's type depending on 
    the configuration or environment.
*/
int main()
{
    std::cout << "App: Launched with the AccountPersonalCreator.\n";

    std::unique_ptr<IAccountFactory> personalAccount =
        std::make_unique<AccountPersonalCreator>(AccountPersonalCreator());
    assert(personalAccount->GetAccountType() == "Personal");

    std::cout << "App: Launched with the AccountBusinessCreator.\n";

    std::unique_ptr<IAccountFactory> businessAccount =
        std::make_unique<AccountBusinessCreator>(AccountBusinessCreator());
    Client(*businessAccount);
    assert(businessAccount->GetAccountType() == "Business");

    return 0;
}