## References

    A reference variable is an alias, that is, another name
    for an already existing variable.

    Once a reference is initialized with a variable, either
    the variable name or the reference name may be used to
    refer to the variable.

## References vs Pointers

### 3 Major Differences:
    
- Null references are not allowed. You mmust always ensure
    reference is to legitimately allocated memory space.

- Once reference is initialized, it cannot refer to another
    object. In contrast, pointers may be overriden.

- A reference must be initialized when created, unlike
    pointers, which can be declared and initialized at any
    time.

```
int& GetReference(int value)
{
    int& lvalue = value;
    return lvalue;
}
```
**Note:** the initial value of reference to a non-const must be an lvalue.
Hence, it must be initialized or returned by method.
