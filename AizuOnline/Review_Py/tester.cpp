#include <iostream>

class MyClass {
public:
    int publicAttribute;

    MyClass(int value) : publicAttribute(value) {}
};

int main() {
    MyClass obj1(10);
    MyClass obj2(20);

    // 修改一个对象的公共属性
    obj1.publicAttribute = 100;

    // 输出另一个对象的公共属性
    std::cout << "Public attribute of obj2: " << obj2.publicAttribute << std::endl;

    return 0;
}