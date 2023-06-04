#include <iostream>
#include <stdio.h>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char *name;

    public:
        Marine();
        Marine(int x, int y, const char* marine_name);
        Marine(int x, int y);
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() 
{
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name) 
{
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) 
{
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() 
{ 
    return damage; 
}

void Marine::be_attacked(int damage_earn) 
{
    hp -= damage_earn;
    
    if (hp <= 0) 
        is_dead = true;
}

void Marine::show_status() 
{
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

Marine::~Marine() 
{
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;

    if (name != NULL) 
    {
        delete[] name;
    }
}

class Test {
    char c;

    public:
        Test(char _c) 
        {
            c = _c;
            std::cout << "생성자 호출 " << c << std::endl;
        }
        
        ~Test() 
        { 
            std::cout << "소멸자 호출 " << c << std::endl; 
        }
};

void simple_function() 
{ 
    Test b('b'); 
}

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char *name;

    public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon& pc);
    ~Photon_Cannon();

    void show_status();
};


Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) 
{
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}


Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) 
{
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() 
{
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.

    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략 가능하다.

    if (name) 
        delete[] name;
}

Photon_Cannon::Photon_Cannon(int x, int y) 
{
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
    name = NULL;
}

void Photon_Cannon::show_status() 
{
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

//problem
class stringCustom {
    char *str;
    int len;

    public:
        stringCustom(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
        stringCustom(const char *s);
        stringCustom(const stringCustom &s);
        ~stringCustom();

        void add_string(const stringCustom &s);   // str 뒤에 s 를 붙인다.
        void copy_string(const stringCustom &s);  // str 에 s 를 복사한다.
        int custom_strlen();                       // 문자열 길이 리턴
        void string_print();
};

stringCustom::stringCustom(char c, int n)
{
    str = new char[n];
    for(int i = 0; i < n - 1 ; i ++)
        str[i] = c;

    len = n;
}

stringCustom::stringCustom(const char *s)
{
    len = strlen(s) + 1;
    str = new char[len];
    
    for(int i = 0 ; i < len ; i++)
        str[i] = s[i];
        
}

stringCustom::stringCustom(const stringCustom &s)
{
    len = strlen(s.str) + 1;
    str = new char[len];
    
    for(int i = 0 ; i < s.len ; i++)
        str[i] = s.str[i];
}

stringCustom::~stringCustom()
{
    if(str)
        delete[] str;
}

void stringCustom::add_string(const stringCustom &s)
{
    int i = 0;
    char *new_str = new char[(len + s.len - 1)];

    for(i = 0 ; i < len - 1 ; i++)
    {
        new_str[i] = str[i];
    }

    for(i = 0 ; i < s.len - 1  ; i++)
    {
        new_str[i + (len - 1)] = s.str[i];
    }

    len = strlen(new_str) + 1;
    
    delete[] str;
    str = new char[len];

    for(i = 0 ; i < len  ; i++)
    {
        str[i] = new_str[i];
    }

    delete[] new_str;
}

void stringCustom::copy_string(const stringCustom &s)
{
    len = s.len;

    if(str)
        delete[] str;

    str = new char[strlen(s.str) + 1];
    
    for(int i = 0 ; i < s.len ; i++)
        str[i] = s.str[i];

}

int stringCustom::custom_strlen()
{
    return len;
}

void stringCustom::string_print()
{
    std::cout << "문자는 : " << str << std::endl;
}

int main()
{
    // skaskawl - 2023.06.04 : copy constructor & destructor
#if 0
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Simon Kim");
    marines[1] = new Marine(1, 5, "Jokn Kim");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];

    //function이 끝날때나 main이 끝날때 class가 반환될때 소멸자도 호출됨 main이 끝날때도 마찬가지
    Test a('a');
    simple_function();

    //복사 생성자 copy constructor
    //default로 두지말고 Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc)만들어쓰면 문제 X
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2(pc1);

    pc1.show_status();
    pc2.show_status();
#else
    //problem
    stringCustom a('c',10);
    stringCustom b = a;
    stringCustom d("xyzuiqwkljndqlkdjaslkdjaslkdjaskl");
    stringCustom c("abcdefg");

    a.string_print();
    b.string_print();
    c.string_print();
    d.string_print();
    std::cout << "-------------------------------" << std::endl;

    a.add_string(d);
    b.add_string(d);
    c.add_string(d);

    a.string_print();
    b.string_print();
    c.string_print();
    std::cout << "-------------------------------" << std::endl;

    a.copy_string(d);
    b.copy_string(d);
    c.copy_string(d);

    a.string_print();
    b.string_print();
    c.string_print();
    std::cout << "-------------------------------" << std::endl;


#endif
    return 0;
}