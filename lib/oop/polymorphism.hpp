#include <iostream>
 
/*
    Polymorphism is closely linked to the concept of Inheritance, which
    allows us to inherit attributes and methods from another class.

    However, Polymorphism allows us to perform the inherited methods in
    different ways, thus overriding the inherited behaviours.
*/

/*
    Base Class
*/

class Shape {
protected:
    /*
        Protected members may only be accessed by inherited/derived classes
    */
    int width, height;

public:
    Shape(int a = 0, int b = 0)
    {
        width = a;
        height = b;
    }
    int area()
    {
        return (width * height);
    }
};

/*
    Derived Classes
*/

class Rectangle: public Shape {
public:
    Rectangle(int a = 0, int b = 0)
        : Shape(a, b)
    {
    }

    int area ()
    {
        return (width * height);
    }
};

class Triangle: public Shape {
public:
    Triangle(int a = 0, int b = 0)
        : Shape(a, b)
    {
    }

    int area ()
    {
        return (width * height / 2);
    }
};
