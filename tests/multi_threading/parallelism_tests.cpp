#include "lib/multi_threading/parallelism.hpp"

void* print_message_function(void *ptr)
{
    char *msg = (char *) ptr;
    printf("%s\n", msg);
}

int main()
{
    const char* msg = "hello";
    Parallelism::nmap(5, print_message_function, msg);

    return 0;
}