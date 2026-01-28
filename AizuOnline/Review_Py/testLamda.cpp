#include <iostream>

int globalVar = 20;
int main() {
    auto lambda = []() {  // 通过引用捕获所有局部变量
        globalVar += 5;
        std::cout << "Global variable: " << globalVar << std::endl;
    };

    int localVar = 21;
    auto localLambda = [lv = localVar]() {  // 通过值捕获所有局部变量
        //lv += 5; //not mutable
        std::cout << "Local variable: " << lv + 5 << std::endl;
    };


    lambda();  // 调用lambda表达式
    localLambda();
    std::cout<<"now global:"<<globalVar<<std::endl;
    std::cout<<"now local:"<<localVar<<std::endl;


    return 0;
}