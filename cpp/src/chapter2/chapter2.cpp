/* skaskawl - 2023.04.22 : standard header file */
#include <iostream>

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

int main ()
{
    /* skaskawl - 2023.04.22 : Chapter 2 */
    //MI_loop();
    MI_switchCase();

    return 0;
}