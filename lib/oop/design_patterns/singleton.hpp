#ifndef SINGLETON
#define SINGLETON

class Singleton
{
public:
    // Copy Constructor
    Singleton(const Singleton&) = delete;
    // Assignment operator
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