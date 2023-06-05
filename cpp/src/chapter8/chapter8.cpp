#include <iostream>
#include <stdio.h>
#include <string.h>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;                // 마린 체력
    int coord_x;            // 마린 위치
    int coord_y;            // 마린 위치
    bool is_dead;

    const int default_damage;

    public:
    Marine();              // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);

    int attack() const;                       // 데미지를 리턴한다.
    Marine& be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();  // 상태를 보여준다.
    static void show_total_marine();

    ~Marine() 
    { 
        total_marine_num--; 
    }
};

//초기값 설정
int Marine::total_marine_num = 0;

void Marine::show_total_marine() 
{
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

//초기화 리스트
/*
 * 초기화 리스트를 하는것은
 * int a = 10; 이고
 *
 * 따로 함수로 하는것은 
 * int a;
 * a =10;으로 하는 것과 같다.
 * const와 같은 변수에는 초기화 리스트를 사용하여 초기값을 정의해줘야한다.
*/
Marine::Marine() : hp(50), coord_x(0), coord_y(0), is_dead(false), default_damage(5) 
{
    total_marine_num++;
}

Marine::Marine(int x, int y) : hp(50), coord_x(x), coord_y(y), is_dead(false), default_damage(5) 
{
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), is_dead(false), default_damage(default_damage) 
{
    total_marine_num++;
}

void Marine::move(int x, int y) 
{
    coord_x = x;
    coord_y = y;
}

int Marine::attack() const
{ 
    return default_damage; 
}

Marine& Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    
    if (hp <= 0) 
        is_dead = true;

    return *this;
}

void Marine::show_status() 
{
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}

class A 
{
    int x;

    public:
        A(int c) : x(c) {}
    
        A(const A& a) 
        {
            x = a.x;
            std::cout << "복사 생성" << std::endl;
        }
};

class B 
{
    A a;

    public:
        B(int c) : a(c) {}
        
        B(const B& b) : a(b.a) {}
    
        A get_A()
        {
            A temp(a);
            return temp;
        }
};

int main()
{
    // skaskawl - 2023.06.05 : Constructor Initializer List & const/static in Class & Reference type return & this Pointer & const member func
#if 0
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
#else
    //problem
    B b(10);

    std::cout << "---------" << std::endl;
    A a1 = b.get_A();
#endif
    return 0 ;
}