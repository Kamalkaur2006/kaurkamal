#include <iostream>

using namespace std;

class MyClass {
private:
    int data;

public:
    MyClass(int d);
    void setData(int d);
    int getData() const;
};

MyClass::MyClass(int d) {
    data = d;
}

void MyClass::setData(int d) {
    data = d;
}

int MyClass::getData() const {
    return data;
}

int main() {
    MyClass obj(10);
    cout << "Initial data: " << obj.getData() << endl;
    obj.setData(20);
    cout << "Updated data: " << obj.getData() << endl;

    return 0;
}
