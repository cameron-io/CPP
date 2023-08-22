
## Multiple Return Types

A common way to handle multiple results returned from a function includes constructing a struct to model/contain the return values

```
struct Result
{
    std::string Body;
    int Code;
    struct Headers;
};
```
While it is also possible to simply use pointers as the input parameters to the function, thus modify values at the address of the pointer; not only would this cause side effects in the program which would require carefully managing the object's lifetime & may cause many potential bugs, it may also require copies of the original values to prevent accidentally overwritten variables.
