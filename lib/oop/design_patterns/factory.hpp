#include <iostream>
#include <string>

/*
    Base Interface & its Implementations
*/
class IProduct {
public:
    virtual ~IProduct() {}
    virtual std::string GetName() const = 0;
};

class Product1 : public IProduct {
public:
    std::string GetName() const override
    {
        return "Product1";
    }
};
class Product2 : public IProduct {
public:
    std::string GetName() const override
    {
        return "Product2";
    }
};


/*
    The Creator class declares the factory method that 
    returns an implementation of the Product class.

    The Creator's subclasses usually provide the
    implementation of this method.
*/
class IProductProvider {
 public:
    virtual ~IProductProvider() {};

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
            + product->GetName();

        delete product;

        return result;
    }
};

/*
    Implementation for Creator overrides the factory method,
    thus changing the resulting product's type.
*/
class ProductProvider1 : public IProductProvider {
    /*
        Note that the signature of the method
        still uses the abstract product type
    */
public:
    IProduct* GetProduct() const override
    {
        return new Product1();
    }
};

class ProductProvider2 : public IProductProvider {
public:
    IProduct* GetProduct() const override
    {
        return new Product2();
    }
};
