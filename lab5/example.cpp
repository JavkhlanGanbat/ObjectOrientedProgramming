#include <iostream>
#include <cstring>

class aClass {
private:
    int a;
    char* name;

public:
    aClass() {
        a = 0;
        name = new char[1];
        name[0] = '\0';
    }

    aClass(int c, const char* n)  {
        c = 0;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~aClass() {
        delete[] name;
    }

    void display() const {
        std::cout << "a: " << a  << ", name: " << name << std::endl;
    }
};

int main() {
    aClass* arr[2];

    arr[0] = new aClass(1, "ClassA");
    arr[1] = new aClass(3, "ClassB");

    std::cout << "Objects:" << std::endl;
    arr[0]->display();
    arr[1]->display();

    delete arr[0];
    delete arr[1];

    return 0;
}
