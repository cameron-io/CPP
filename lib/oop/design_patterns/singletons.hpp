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
    void SomeFunction() {}

private:
    Singleton() {}

    float m_Data = 0.0f;

    // Instance is declared in translation unit
    static Singleton s_Instance;
};

/*
    Random Number Generator
*/
class Random
{
public:
    Random(const Random&) = delete;
    Random& operator=(const Random) = delete;

    static Random& Get() 
    {
        static Random instance;
        return instance;
    }

    static float Float() { return Get().FloatInternal(); }

private:
    Random() {}

    float FloatInternal() { return m_RandomGenerator; }

    float m_RandomGenerator = 0.5f;
};

#endif