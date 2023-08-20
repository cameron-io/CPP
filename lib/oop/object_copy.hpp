#include <string>
#include "string.h"
#include <stdexcept>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        // init new char array
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        // ensure null termination
        m_Buffer[m_Size] = 0;
    }

    String(const String& other)
        : m_Size(other.m_Size)
    {
        // Allocate new buffer for object copy
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        if (index > this->m_Size)
            throw std::invalid_argument("out of bounds");
        
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(
        std::ostream& stream,
        const String& string);
};