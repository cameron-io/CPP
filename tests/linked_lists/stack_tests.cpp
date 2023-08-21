#include <memory>

#include "lib/linked_lists/stack.hpp"

int main()
{
    Stack* stack = new Stack();
    
    stack->push("Jaguar");
    stack->push("Envision");
    stack->push("Avalanche");
    stack->push("McLaren");

    std::cout << "1. initial values:" << std::endl;
    stack->print();
    
    stack->pop();
    
    std::cout << "2. new values:" << std::endl;
    stack->print();

    delete stack;

    return 0;
}
