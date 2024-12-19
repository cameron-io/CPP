#ifndef ACCOUNT_BUSINESS_CREATOR
#define ACCOUNT_BUSINESS_CREATOR

#include "../domain/IAccount.hpp"
#include "../domain/IAccountFactory.hpp"
#include "../application/AccountBusiness.hpp"

/*
    Implementation for Creator overrides the factory method to 
    instantiate a specific concrete product class.
*/
class AccountBusinessCreator : public IAccountFactory {
public:
    /*
        Note that the signature of the method
        still uses the abstract product type
    */
    std::unique_ptr<IAccount> CreateAccount() const override
    {
        return std::make_unique<AccountBusiness>(AccountBusiness());
    }
};

#endif