#include <iostream>

class MyString {
    char* string_content;  // 문자열 데이터를 가리키는 포인터
    int string_length;     // 문자열 길이

    int memory_capacity;

    public:
    // capacity 만큼 미리 할당함. (explicit 키워드에 주목)
    explicit MyString(int capacity);

    // 문자열로 부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
    int capacity() const;
};

#if 0
class Server {
  // .... (생략) ....

  mutable Cache cache; // 캐쉬!

  // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
  User GetUserInfo(const int user_id) const {
    // 1. 캐쉬에서 user_id 를 검색
    Data user_data = cache.find(user_id);

    // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
    if (!user_data) {
      user_data = Database.find(user_id);

      // 그 후 캐쉬에 user_data 등록
      cache.update(user_id, user_data); // <-- 불가능
    }

    // 3. 리턴된 정보로 User 객체 생성
    return User(user_data);
  }
};
#endif

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s) {
  // Do something...
}

int main() {
    // skaskawl - 2023.06.25 : explicit & mutable
    // explicit으로 선언 할 경우 명시적으로 기입해야 컴파일러가 수행함
    // mutable 로 선언한 변수는 const 함수안에서 데이터 변경이 가능함
    //DoSomethingWithString(3);  // ????
}