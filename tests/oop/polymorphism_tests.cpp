#include "lib/oop/polymorphism.hpp"

int main()
{
    /*
        Base Class is Declared
    */
    Shape *shape;
    
    /*
        Derived Classes are Instantiated
    */
    Rectangle rectangle(10,7);
    Triangle triangle(10,5);

    /*
        Store the address of Rectangle in Base Class
    */
    shape = &rectangle;

    // Calls Rectangle->area.
    shape->area();

    /*
        Store the address of Triangle in Base Class
    */
    shape = &triangle;

    // Calls Triangle->area.
    shape->area();

    return 0;
}