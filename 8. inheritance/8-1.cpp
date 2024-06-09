#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    void set(int x, int y) {this->x = x; this->y = y;}
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) {this->color = color; }
    void showColorPoint();  
};

void ColorPoint::showColorPoint() {
    cout << color << ":";
    showPoint(); // Point의 showPoint() 호출
}

int main() {
    Point p; // 기본 클래스의 객체 생성
    ColorPoint cp; // 파생 클래스의 객체 생성
    cp.set(3, 4); // 기본 클래스의 멤버 호출
    cp.setColor("Red"); // 파생 클래스의 멤버 호출
    cp.showColorPoint(); // 파생 클래스의 멤버 호출
}