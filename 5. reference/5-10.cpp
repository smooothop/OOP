#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char *name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    ~Person(); // 소멸자
    void changeName(const char *name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char *name){
    this->id = id;
    int len = strlen(name); // name 의 문자 개수
    this->name = new char [len+1]; // name 문자열 공간 할당
    strcpy(this->name, name); // name에 문자열 복사
}

Person::~Person() {
    if(name) // 만일 name에 동적 할당된 배열이 있으면
        delete [] name; // 동적 할당 메모리 소멸
}   

void Person::changeName(const char* name){
    if(strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

int main(){
    Person father(1, "Kitae");  // (1) father 객체 생성
    Person daughter(father);    // (2) daughter 객체 복사 생성. 복사생성자호출

    cout << "daughter 객체 생성 직후 ____" << endl;
    father.show();              // (3) father 객체 출력
    daughter.show();            // (3) daughter 객체 출력

    daughter.changeName("Grace"); // (4) daughter의 이름을 "Grace"로 변경
    cout << "daughter 이름을 Grace로 변경한 후 ____" << endl;
    father.show();              // (5) father 객체 출력
    daughter.show();            // (5) daughter 객체 출력

    return 0;
}