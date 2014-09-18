#include <iostream>

class TestA
{
public:
    TestA()
    {
        std::cout << "TestA Contructor" << std::endl;
    }
    ~TestA()
    {
        std::cout << "TestA Destructor" << std::endl;
    }
};

class TestB
{
public:
    TestB()
    {
        std::cout << "TestB Constructor" << std::endl;
    }

    ~TestB()
    {
        std::cout << "TestB Destructor" << std::endl;
    }
};

class TestC
{
public:
    TestC()
    {
        ta = new TestA();
        tb = new TestB();
        throw std::string("something trigger a exception");
        std::cout << "TestC() Constructor" << std::endl;
    }

    ~TestC()
    {
        delete ta;
        delete tb;
        std::cout << "TestC() Destructor" << std::endl;
    }

private:
    TestA* ta;
    TestB* tb;
};

class TestD
{
public:
    TestD()
    {
        try
        {
            ta = new TestA();
            tb = new TestB();
            throw std::string("something trigger a exception");
        }
        catch(const std::string& exp)
        {
            std::cout << exp << std::endl;
            cleanup();
            throw;
        }

        std::cout << "TestD() Constructor" << std::endl;
    }

    ~TestD()
    {
        cleanup();
        std::cout << "TestD() Destructor" << std::endl;
    }

    void cleanup()
    {
        delete ta; ta = NULL;
        delete tb; tb = NULL;
    }

private:
    TestA* ta;
    TestB* tb;
};

int main()
{
    try
    {
        TestC tc;
    }
    catch (const std::string& exp)
    {
        std::cout << exp << std::endl;
    }

    try
    {
        TestD td;
    }
    catch (...)
    {
        std::cout << "construtor failure." << std::endl;
    }
}
