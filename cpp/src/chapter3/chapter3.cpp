/* skaskawl - 2023.04.22 : standard header file */
#include <iostream>

int MI_Ref_ChangeVal()
{
    int a = 5;
	std::cout << "function 함수 내부에서 a의 주소값 : " << &a << std::endl;;
	return a;
}


/* skaskawl - 2023.04.22 : main loop */
int main ()
{
    /* skaskawl - 2023.05.02 : Chapter 3 Reference*/
    const int& c = MI_Ref_ChangeVal();
	std::cout << "c : " << c << std::endl;
	std::cout << "const int& c의 주소값 : " << &c << std::endl;
    return 0;
}