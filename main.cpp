#include <iostream>

class Singleton {
protected:
    Singleton() = default;
    Singleton(const Singleton &) = delete; // Copy constructor This will prevent creating more than one object of Singleton class
                                            // not include this function on our class

    Singleton &operator=(const Singleton &) = delete; // Copy assignment operator This will prevent creating more than one object of Singleton class
                                            // not include this function on our class
    Singleton(Singleton &&) = delete; // Move constructor is deleted, // This will prevent creating more than one object of Singleton class
                                            // not include this function on our class
    Singleton &operator=(Singleton &&) = delete; // Move assignment operator is deleted, // This will prevent creating more than one object of Singleton class
                                            // not include this function on our class

public:
    int data;

    static Singleton &getInstance() {
        static Singleton instance; // This is a static variable, it will be created only once, thread safe and it will be destroyed when the program ends
                                    // can be used by all the threads  (static variable) and it will be created only once
        return instance;
    }
};

int main() {
    // Singleton singleton = Singleton::getInstance(); // This a copy constructor call, we have to make a copy constructor as deleted in order
                                                    // to prevent creating more that one object of Singleton class
    Singleton &s1 = Singleton::getInstance();
    s1.data = 10;
    std::cout << "s1.data = " << s1.data << std::endl;

    Singleton &s2 = Singleton::getInstance();
    std::cout << "s2.data = " << s2.data << std::endl;


    // Singleton s3; //Error: Singleton::Singleton() is protected
    // we can't create an object of Singleton class

    // We can call directly the static function, we don't need to call it via reference
    Singleton::getInstance().data = 20;
    std::cout << "Singleton::getInstance().data = " << Singleton::getInstance().data << std::endl;
    std::cout << "s1.data = " << s1.data << std::endl;
    std::cout << "s2.data = " << s2.data << std::endl;
    // All the three objects have the same value of data

    return 0;
}
