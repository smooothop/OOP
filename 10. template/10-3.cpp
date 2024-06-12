#include <iostream>
using namespace std;

template <class T>
T add(T data [], int n) { // 배열 data에서 n개의 원소를 합한 결과를 리턴
    T sum = 0;
    for(int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum; // sum와 타입과 리턴 타입이 모두 T로 선언되어 있음
}

int main() {
    int x[] = {1, 2, 3, 4, 5};
    double d[] = {1.2, 2.3, 3.4};

    cout << "sum of x[] = " << add(x, 5) << endl; // 배열 x와 원소 5개의 합을 계산
    cout << "sum of d[] = " << add(d, 6) << endl; // 배열 d와 원소 6개의 합을 계산
}