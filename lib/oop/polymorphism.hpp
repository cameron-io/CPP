#include <iostream>
 
class Shape {
protected:
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
