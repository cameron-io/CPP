#include <iostream>
#include <string>

/*
    Base Interface & its Implementations
*/
class IProduct {
public:
    virtual ~IProduct() {}
    virtual std::string Entity() const = 0;
};

class ImplProduct1 : public IProduct {
public:
    std::string Entity() const override
    {
        return "ImplProduct1";
    }
};
class ImplProduct2 : public IProduct {
public:
    std::string Entity() const override
    {
        return "ImplProduct2";
    }
};


/*
    The Creator class declares the factory method that 
    returns an implementation of the Product class.

    The Creator's subclasses usually provide the
    implementation of this method.
*/
class Creator {
 public:
    virtual ~Creator() {};

    /*
        This is known as the Factory Method
    */
    virtual IProduct* GetProduct() const = 0;

    /*
        The Creator contains core business logic that
        relies on Product objects returned by the
        factory method.
    */
    std::string UseProduct() const
    {
        /*
            Call the factory method to create a Product object. 
        */
        IProduct* product = this->GetProduct();
        
        std::string result =
            "The creator just worked with Product: "
            + product->Entity();

        delete product;

        return result;
    }
};

/*
    Implementation for Creator overrides the factory method,
    thus changing the resulting product's type.
*/
class ImplCreator1 : public Creator {
    /*
        Note that the signature of the method
        still uses the abstract product type
    */
public:
    IProduct* GetProduct() const override
    {
        return new ImplProduct1();
    }
};

class ImplCreator2 : public Creator {
public:
    IProduct* GetProduct() const override
    {
        return new ImplProduct2();
    }
};
