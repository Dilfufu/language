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

/* skaskawl - 2023.04.22 : main loop */
int main ()
{
    /* skaskawl - 2023.04.22 : Chapter 1 */
    //MI_printHelloWorld();
    
    /* skaskawl - 2023.04.22 : Chapter 2 */
    //MI_loop();
    //MI_switchCase();

    /* skaskawl - 2023.04.22 : Chapter 3 Reference*/
    //MI_Reference();

    return 0;
}