#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() {radius = 1;}
    Circle(int r) {radius = r;}
    void setRadius(int r){radius = r;}
    double getArea();
};

double Circle::getArea(){
    return 3.14 * radius * radius;
}

int main(){
    Circle circleArray[3];

    // 배열의 각 원소 객체의 멤버 접근
    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);
}