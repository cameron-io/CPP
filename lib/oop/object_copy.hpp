#include <ostream>
#include <string>
#include "string.h"
#include <stdexcept>

/*
    Object copying in a C-style approach for demonstration purposes
    - not production-ready
*/

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    /*
        Constructor
    */
    String(const char* string)
    {
        m_Size = strlen(string);
        // store string buffer in heap
        // +1 size for guaranteed null termination
        m_Buffer = new char[m_Size + 1];
        // copy passed new char[] to buffer
        memcpy(m_Buffer, string, m_Size);
        // ensure null termination present
        m_Buffer[m_Size] = 0;
    }

    /*
        Object Copy Constructor
    */
    String(const String& other)
        // Initialize member values
        : m_Size(other.m_Size)
    {
        // Allocate new buffer for object copy
        m_Buffer = new char[m_Size + 1];
        // copy other value of other buffer into this buffer
        memcpy(m_Buffer, other.m_Buffer, m_Size);
        // ensure null termination present
        m_Buffer[m_Size] = 0;
    }

    /*
        Desctructor
    */
    ~String()
    {
        delete[] m_Buffer;
    }

    // Operator overrides

    /*
        Ensure char array index operator value within bounds
    */
    char& operator[](unsigned int index)
    {
        if (index > this->m_Size)
            throw std::invalid_argument("out of bounds");
        
        return m_Buffer[index];
    }

    /*
        Print a String object m_Buffer to an output stream:
        - friend:
            -> Grants the function access to the private and protected members of the
               String class, even though it's not a member function itself.
        - operator<<:
            -> This is the overloaded stream insertion operator. It allows you to use the 
               << operator with a String object and an output stream.
        - std::ostream&:
            -> It's a reference to an ostream object, which is the output stream where the data
               will be written (usually cout or a file stream).
        - const String&:
            -> Read-only constant reference to a String object.
    */
    friend std::ostream& operator<<(
        std::ostream& stream,
        const String& string)
    {
        stream << string.m_Buffer;
        return stream;
    }
};