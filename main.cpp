#include <iostream>

class Singleton {
protected:
    Singleton() = default;

public:
    int data;

    static Singleton &getInstance() {
        static Singleton instance;
        return instance;
    }
};

int main() {
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
