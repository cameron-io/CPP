#ifndef ACCOUNT_BUSINESS_H
#define ACCOUNT_BUSINESS_H

#include "../domain/IAccount.hpp"
#include <string>

class AccountBusiness : public IAccount {
public:
    std::string GetType() const override
    {
        return "Business";
    }
};

#endif