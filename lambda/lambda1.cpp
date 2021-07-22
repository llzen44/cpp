#include <iostream>

using namespace std;

void log (int a){
    cout << "a = " << a << endl;
}

int main() {
    int a = 42;
    log(a);
    
    [a](){
        cout << "lambda with capture, a = " << a << endl;
        //a++;
    }();
    log(a);

    [](int a){
        cout << "lambda with parameter, a = " << a << endl;
        a++;
    }(a);
    log(a);

    [](int* a){
        cout << "lambda with parameter pointer, a = " << *a << endl;
        (*a)++;
    }(&a);
    log(a);

    auto lambda = [](int& a){
        cout << "lambda with parameter reference, a = " << a << endl;
        a++;
    };
    lambda(a);
    log(a);
    
    int* ptr_a = &a;
    [ptr_a](){
        cout << "lambda with capture pointer, a = " << *ptr_a << endl;
        (*ptr_a)++;
    }();
    log(a);
    
    return 0;
}
