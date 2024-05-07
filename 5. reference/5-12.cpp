#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char* name;
    int id;
public:
    Person(int id, const char* name); // 생성자
    Person(const Person& person); // 보갓 생성자
    ~Person(); // 소멸자
    void changeName(const char *name);
    void show() {cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name){
    this->id = id;
    int len = strlen(name); // name의 문자 개수
    this->name = new char [len + 1]; // name 문자열 공간 할당
    strcpy(this->name, name); // name에 문자열 복사
}

Person::Person(const Person& person) {
    this->id = person.id; // id값 복사
    int len = strlen(person.name); // name의 문자 개수
    this->name = new char [len + 1]; // name을 위한 공간 할당
    strcpy(this->name, person.name); // name의 문자열 복사
    cout << "복사 생성자 실행, 원본 객체의 이름 " << this->name << endl;
}

Person::~Person(){
    if(name) // 만일 name에 동적 할당된 배열이 있으면
        delete [] name; // 동적 할당 메모리 소멸
}

void Person::changeName(const char* name) {
    if(strlen(name) > strlen(this->name))
        return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
    strcpy(this->name, name);
}

void f(Person person){
    person.changeName("dummy");
}

Person g(){
    Person mother(2, "Jane");
    return mother;
}

int main(){
    
    Person father(1, "Kitae");
    Person son = father;
    f(father);
    g();

    return 0;
}