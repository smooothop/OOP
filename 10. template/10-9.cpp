#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v; // 정수만 삽입 가능한 벡터 생성

    v.push_back(1); // 벡터에 정수 1 삽입
    v.push_back(2); // 벡터에 정수 2 삽입
    v.push_back(3); // 벡터에 정수 3 삽입

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " "; // v[i]는 벡터의 i번째 원소
    cout << endl;

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " "; // v[i]는 벡터의 i번째 원소
    cout << endl;

    v[0] = 10;
    int n = v[2];
    v.at(2) = 5;

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " "; // v[i]는 벡터의 i번째 원소
    cout << endl;
}