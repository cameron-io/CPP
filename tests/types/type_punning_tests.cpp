#include <boost/assert.hpp>

int primitives()
{
    int a = 50;
    /*
        This is Type Punning
        
        As a result of the conversion in this example, 
        we are trying to read an int from a double as
        if it was still occupying 4 bits of memory.

                    4 bytes     8 bytes
        int     32 00 00 00
        double  32 00 00 00 cc cc cc cc

        Therefore, this should only be performed between
        types of the same memory allocation
    */
    double b = * (double*) &a;

    return b;
}

/*
    More practical example of using Type Punning
*/

struct Graph
{
    int x, y;
};

int* struct_to_list(Graph g)
{
    /*
        casting struct to an int pointer will treat the contiguous
        memory stored in the struct as a list
    */
    int* array = (int*) &g;

    return array;
}

/*
    Time to get interesting.

    This will reduce down to pointer arithmetic using 
    type punning, in order to derive the value stored
    at the memory allocated in the struct
*/

int get_y(Graph g)
{
    /*
        Here, the struct is once again converted:

        - however, we are targeting a single byte in
          memory occupied by the 'char' type;
        
        - then, using an offset of '+4' to move the pointer 
          forward to the position of the y co-ordinate;
        
        - finally, we type pun once more to identify the
          4 bytes occupied by the integer, then dereference
          the value at this address.
    */
    int y = *(int *)((char*) &g + 4);

    return y;
}

int main()
{
    Graph g = {1, 2};

    int* coordinates = struct_to_list(g);

    assert(coordinates[1] == 2);

    assert(get_y(g) == 2);
}
