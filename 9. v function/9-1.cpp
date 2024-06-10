#include <iostream>
using namespace std;

class Base {
public:
    void f() { cout << "Base::f()called" << endl; }
};

class Derived : public Base {
public:
    void f() { cout << "Base::f()called" << endl; }
};

void main() {
    Derived d, *pDer;
    pDer = &d;
    pDer->f(); // Derived::f() 호출

    Base* pBase;
    pBase = pDer; // 업캐스팅
    pBase->f(); // Base::f() 호출
}