#include "lib/linked_lists/queue.hpp"

int main()
{
    auto queue = new Queue();

    queue->enqueue("Jaguar");
    queue->enqueue("Envision");
    queue->enqueue("Avalanche");
    queue->enqueue("McLaren");

    std::cout << "1. initial values:" << std::endl;
    queue->print();

    queue->dequeue();
    
    std::cout << "2. new values:" << std::endl;
    queue->print();

    delete queue;

    return 0;
}
