#ifndef ACCOUNT_PERSONAL_H
#define ACCOUNT_PERSONAL_H

#include "../domain/IAccount.hpp"
#include <string>

class AccountPersonal : public IAccount {
public:
    std::string GetType() const override
    {
        return "Personal";
    }
};

#endif