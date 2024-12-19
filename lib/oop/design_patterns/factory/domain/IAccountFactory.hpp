#ifndef IACCOUNT_FACTORY_H
#define IACCOUNT_FACTORY_H

#include "IAccount.hpp"
#include "../application/AccountBusiness.hpp"
#include "../application/AccountPersonal.hpp"
#include <iostream>
#include <string>

/*
    The Creator class declares the factory method that 
    returns an implementation of the Product class.

    The Creator's subclasses usually provide the
    implementation of this method.
*/
class IAccountFactory {
 public:
    virtual ~IAccountFactory() {};

    /*
        This is known as the Factory Method
    */
    virtual IAccount* CreateAccount() const = 0;

    /*
        The Creator contains core business logic that
        relies on Product objects returned by the
        factory method.
    */
    std::string GetAccountType() const
    {
        /*
            Call the factory method to create a Product object. 
        */
        IAccount* account = this->CreateAccount();
        std::string accountType = account->GetType();
        
        std::string result =
            "The creator just worked with Product: "
            + account->GetType();

        delete account;

        return accountType;
    }
};

#endif