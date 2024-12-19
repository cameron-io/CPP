#ifndef ACCOUNT_PERSONAL_CREATOR
#define ACCOUNT_PERSONAL_CREATOR

#include "../domain/IAccount.hpp"
#include "../domain/IAccountFactory.hpp"
#include "../application/AccountPersonal.hpp"

/*
    Implementation for Creator overrides the factory method to 
    instantiate a specific concrete product class.
*/
class AccountPersonalCreator : public IAccountFactory {
public:
    IAccount* CreateAccount() const override
    {
        return new AccountPersonal();
    }
};

#endif