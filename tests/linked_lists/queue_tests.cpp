#include "lib/linked_lists/queue.hpp"

int main()
{
    auto queue = new Queue();

    queue->enqueue(30);
    queue->enqueue(20);
    queue->enqueue(40);
    queue->enqueue(10);

    std::cout << "1. initial values:" << std::endl;
    queue->print();

    queue->dequeue();
    
    std::cout << "2. new values:" << std::endl;
    queue->print();

    delete queue;

    return 0;
}
