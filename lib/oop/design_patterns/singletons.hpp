#ifndef SINGLETON
#define SINGLETON

/*
    Common Singleton Pattern:
    - used in OOP languages, eg. Java 
*/
class Singleton
{
public:
    /*
        Remove Copy Constructor to prevent
        accidental instance copies created, 
        causing data duplication
    */
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton) = delete;

    static Singleton& GetInstance()
    {
        return s_Instance;
    }
    void IncrementCounter()
    {
        m_Counter++;
    }
    int GetCounterValue()
    {
        return GetInstance().m_Counter;
    }

private:
    Singleton() {}

    int m_Counter = 0;

    // Instance is declared in translation unit
    static Singleton s_Instance;
};

#endif