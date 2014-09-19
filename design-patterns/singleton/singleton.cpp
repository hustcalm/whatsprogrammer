class Lock {
    private:
        CRITICAL_SECTION &m_cs;
    public:
        Lock(CRITICAL_SECTION &cs): m_cs(cs) {
            m_cs.lock();
        }

        ~Lock() {
            m_cs.unlock();
        }
}

class Singleton {
    private:
        Singleton();
        Singleton(const Singleton&);
        Singleton operator = (const Singleton&);

    public:
        static Singleton* getInstance();
        static Singleton* pInstance;
        static CRITICAL_SECTION cs;
};

Singleton* Singleton::pInstance = NULL;
Singleton* Singleton::getInstance() {
    if(pInstance == NULL) {
        Lock lock(cs);
        if(pInstance == NULL) {
            pInstance = new Singleton();
        }
    }
    return pInstance;
}
