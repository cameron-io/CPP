#include <iostream>
#include <string>

/*
    Base Interface & its Implementations
*/
class IBankAccount {
public:
    virtual ~IBankAccount() {}
    virtual std::string GetType() const = 0;
};

class PersonalBankAccount : public IBankAccount {
public:
    std::string GetType() const override
    {
        return "Personal";
    }
};
class BusinessBankAccount : public IBankAccount {
public:
    std::string GetType() const override
    {
        return "Business";
    }
};


/*
    The Creator class declares the factory method that 
    returns an implementation of the Product class.

    The Creator's subclasses usually provide the
    implementation of this method.
*/
class IBankAccountFactory {
 public:
    virtual ~IBankAccountFactory() {};

    /*
        This is known as the Factory Method
    */
    virtual IBankAccount* CreateAccount() const = 0;

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
        IBankAccount* account = this->CreateAccount();
        
        std::string result =
            "The creator just worked with Product: "
            + account->GetType();

        delete account;

        return result;
    }
};


/*
    Implementation for Creator overrides the factory method to 
    instantiate a specific concrete product class.
*/
class PersonalBankAccountCreator : public IBankAccountFactory {
public:
    /*
        Note that the signature of the method
        still uses the abstract product type
    */
    IBankAccount* CreateAccount() const override
    {
        return new PersonalBankAccount();
    }
};

class BusinessBankAccountCreator : public IBankAccountFactory {
public:
    IBankAccount* CreateAccount() const override
    {
        return new BusinessBankAccount();
    }
};
