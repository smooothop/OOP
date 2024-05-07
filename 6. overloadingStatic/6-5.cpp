#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') {
    for(int i = 0; i < n; i++) cout << c;
    cout << endl;
}

int main(){
    fillLine(); // 25개의 '*'를 한 라인에 출력
    fillLine(10, '%'); // 10개의 '%'를 한 라인에 출력
}