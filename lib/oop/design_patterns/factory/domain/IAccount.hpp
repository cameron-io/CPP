#ifndef IACCOUNT_H
#define IACCOUNT_H

#include <string>

class IAccount {
public:
    virtual ~IAccount() {}
    virtual std::string GetType() const = 0;
};

#endif