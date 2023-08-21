#include "lib/oop/polymorphism.hpp"

int main()
{
    Shape *shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);

    // store the address of Rectangle
    shape = &rec;

    // call rectangle area.
    shape->area();

    // store the address of Triangle
    shape = &tri;

    // call triangle area.
    shape->area();

    return 0;
}