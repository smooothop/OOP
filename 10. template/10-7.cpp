#include <iostream>
using namespace std;

template <class T>
class MyStack {
    int tos; // top of stack
    T data[100];
public:
    MyStack();
    void push(T element);
    T pop();
};

template <class T>
MyStack<T>::MyStack() {
    tos = -1; // 스택은 비어 있음
}

template <class T>
void MyStack<T>::push(T element) {
    if(tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
}
template <class T>
T MyStack<T>::pop() {
    T retData;
    if(tos == -1) {
        cout << "stack empty";
        return 0;
    }
    retData = data[tos--];
    return retData;
}

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) {this->x = x; this->y = y;}
    void show() { cout << '(' << x << ',' << y << ')' << endl; }
};

int main() {
    MyStack<int *> ipStack; // int*만을 저장하는 스택
    int *p = new int [3]; // 3크기의 동적 배열 할당
    for(int i = 0; i < 3; i++)
        p[i] = i * 10;
    ipStack.push(p); // 포인터 푸시
    int *q = ipStack.pop(); // 포인터 팝
    
    for(int i = 0; i < 3; i++)
        cout << q[i] << ' '; // 화면 출력
    cout << endl;
    delete [] p;

    MyStack<Point> pointStack; // Point 객체 저장 스택
    Point a(2, 3), b;
    pointStack.push(a); // Point 객체 a 푸시. 복사되어 저장
    b = pointStack.pop(); // Point 객체 팝
    b.show(); // Point 객체 출력

    MyStack<Point*> pStack; // Point* 포인터 스택
    pStack.push(new Point(10, 20));
    Point* pPoint = pStack.pop();
    pPoint->show();

    MyStack<string> stringStack; // 문자열만 저장하는 스택
    string s = "c++";
    stringStack.push(s);
    stringStack.push("java");
    cout << stringStack.pop() << ' ';
    cout << stringStack.pop() << endl;
}