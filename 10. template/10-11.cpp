#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it; // 벡터 v의 원소에 대한 포인터 it 선언

    for(it = v.begin(); it != v.end(); it++) {
        int n = *it; // it가 가리키는 원소 값 리턴
        n = n * 2; // 곱하기 2
        *it = n; // it가 가리키는 원소에 값 쓰기
    }

    for(it = v.begin(); it != v.end(); it++)
        cout << *it << ' ';
    cout << endl;
}