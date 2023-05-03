/*
 * Copyright 
 * Author       : skaskawl
 * Date         : 2023.04.22
 * Description  : c++ Study Source File
 * History      
 *  skaskawl - 2023.04.22 : First Create
 * 
 * 
*/

/* skaskawl - 2023.04.22 : standard header file */
#include <iostream>

/* skaskawl - 2023.04.22 : custom header file */
#include <main.h>


int MI_printHelloWorld()
{
    std::cout << "Hello, World!!\n" << "I`m Sunmin Kim\n" << "I`m King" << std::endl;

    std::cout << "hi" << std::endl
          << "my name is "
          << "Psi" << std::endl;

    return 0;
}

int MI_loop()
{
    #if 0
    int i = 0, sum = 0;

    for (i = 0 ; i<=10 ; i++)
    {
        sum += i;
    }

    std::cout << "합은 : " << sum << std::endl;

    i = 1;
    sum = 0;
    
    while(i <= 10)
    {
        sum += i;
        i++;
    }

    std::cout << "합은 : " << sum << std::endl;
    #endif

    int lucky_number = 3;

    std::cout << "내 비밀 수를 맞추어 보세요 ~!" << std::endl;

    int user_input;

    while(1)
    {
        std::cout << "입력 : ";
        std::cin >> user_input;

        if(lucky_number == user_input)
        {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        }
        else
        {
            std::cout << "다시 생각해보세요~" << std::endl;
        }
    }
    
    return 0;
}

using std::cout;
using std::endl;
using std::cin;

int MI_switchCase()
{
    int user_input ;
    cout << "저의 정보를 표시해줍니다" << endl;
    cout <<"1. 이름 " << endl;
    cout <<"2. 나이 " << endl;
    cout <<"3. 성별 " << endl;
    cin >> user_input;

    switch (user_input)
    {
        case 1:
            cout << "Psi ! " << endl;
            break;
        case 2:
            cout << " 99 살" << endl;
            break;
        case 3:
            cout << "남자" << endl;
            break;
        default:
            cout << "궁금한게 없군요~" << endl;
            break;
    }
    
    return 0;
}

int MI_Ref_ChangeVal()
{
    int a = 5;
	std::cout << "function 함수 내부에서 a의 주소값 : " << &a << std::endl;;
	return a;
}

int MI_Reference(void)
{
    const int& c = MI_Ref_ChangeVal();
	std::cout << "c : " << c << std::endl;
	std::cout << "const int& c의 주소값 : " << &c << std::endl;
    return 0;
}

typedef struct Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;
}Animal;

void create_animal(Animal *animal)
{
    std::cout << "동물의 이름은? ";
    std::cin >> animal->name;

    std::cout << "동물의 나이? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal)
{
    animal->health += 10;
    animal->food -=20;
    animal->clean -=30;
}

void one_day_pass(Animal *animal) {
  // 하루가 지나면
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}

void show_stat(Animal *animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << "체력    : " << animal->health << std::endl;
  std::cout << "배부름 : " << animal->food << std::endl;
  std::cout << "청결    : " << animal->clean << std::endl;
}

int MI_NewClassAndDeleteClass(void)
{
    Animal *list[10];
    int animal_num = 0;

    for (;;) 
    {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 상태 보기 " << std::endl;

        int input;
        std::cin >> input;

        switch (input) 
        {
            int play_with;
            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀게? : ";
                std::cin >> play_with;
                if (play_with < animal_num) 
                    play(list[play_with]);
                break;
            case 3:
                std::cout << "누구껄 보게? : ";
                std::cin >> play_with;
                if (play_with < animal_num)
                    show_stat(list[play_with]);
                break;
        }

        for (int i = 0; i != animal_num; i++) 
        {
            one_day_pass(list[i]);
        }
    }
    
    for (int i = 0; i != animal_num; i++) 
    {
        delete list[i];
    }

    return 0;
}

/* skaskawl - 2023.04.22 : main loop */
int main ()
{
    int ret = 0;
    /* skaskawl - 2023.04.22 : Chapter 1 */
    //MI_printHelloWorld();
    
    /* skaskawl - 2023.04.22 : Chapter 2 */
    //MI_loop();
    //MI_switchCase();

    /* skaskawl - 2023.05.02 : Chapter 3 Reference*/
    //MI_Reference();

    /* skaskawl - 2023.05.04 : Chapter 4 New/Delete*/
    #if 0
    ret = MI_NewClassAndDeleteClass();
    if(ret)
    {
        std::cout << "Chapter 4 Error" << std::endl;
        return -1;
    }
    #endif

    /* skaskawl - 2023.??.?? : Chapter 5 객체지향 */

    return 0;
}