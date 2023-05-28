#include <iostream>

class Animal {
    private:
        int food;
        int weight;

    public:
        void set_animal(int _food, int _weight)
        {
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc)
        {
            food += inc;
            weight += (inc / 3);
        }

        void view_stat() 
        {
            std::cout << "이 동물의 food   : " << food << std::endl;
            std::cout << "이 동물의 weight : " << weight << std::endl;
        }
};

class Date {
    private:
        int year_;
        int month_;
        int day_;
        int lastDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int chkDay;
	    int chkMonth;

    public:
	    void SetDate(int year, int month, int date) 
        {
            year_ = year;
            month_ = month;
            day_ = date;

            CheckDate(day_);
            CheckMonth(month_);
	    }

        //일 계산
        void CheckDate(int chkDay) 
        {
		    //윤년
		    if (month_ == 2 ) 
            {
			    if (year_ % 4 == 0) 
                    lastDay[month_ - 1] = 29;
			    else 
                    lastDay[month_ - 1] = 28;
			}

		    if (chkDay > lastDay[month_ - 1]) 
            {
			    chkDay -= lastDay[month_ - 1];
			    month_++;
			    CheckMonth(month_);
			    CheckDate(chkDay);
		    }
		    else 
            {
			    day_ = chkDay;
			    CheckMonth(month_);
		    }
	    }

	    //월 계산
	    void CheckMonth(int chkMonth) 
        {
		    if (chkMonth > 12) 
            {
			    chkMonth -= 12;
			    year_++;
			    CheckMonth(chkMonth);
		    }
		    else 
            {
			    month_ = chkMonth;
		    }
	    }

        void AddDay(int inc) 
        {
            chkDay = day_ + inc;
            CheckDate(chkDay);
        }

        void AddMonth(int inc) 
        {
            chkMonth = month_ + inc;
            CheckMonth(chkMonth);
        }

        void AddYear(int inc) 
        {
            year_ += inc;
        }

        void showDate() 
        {
            std::cout << year_ << "년" << month_ << "월" << day_ << "일" << std::endl;
        }
};

int main ()
{
    /* skaskawl - 2023.05.28 : Object Oriented Language description & Class */
    Animal animal;

    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    
    Date date;
	int year;
	int month;
	int day;
	int input;
	int inc;

	std::cout << " 초기 값을 입력하세요. (년):" << std::endl;
	std::cin >> year;

	std::cout << " 초기 값을 입력하세요. (월):" << std::endl;
	std::cin >> month;

	std::cout << " 초기 값을 입력하세요. (일):" << std::endl;
	std::cin >> day;

	date.SetDate(year, month, day);
	std::cout << "초기 입력값 입니다. " << std::endl;
	date.showDate();

	while (1) {
		std::cout << "  1. 년추가 " << std::endl;
		std::cout << "  2. 월추가 " << std::endl;
		std::cout << "  3. 일추가 " << std::endl;
		std::cout << "  4. 보기 " << std::endl;
		std::cout << "  5. 종료 " << std::endl;
		std::cin >> input;

		if (input < 4 && input > 0 ) {
			std::cout << "증가값 입력: " << std::endl;
			std::cin >> inc;
		}
		else if (input == 5) {
			break;
		}

		switch (input) {
		case 1:
			date.AddYear(inc);
			break;
		case 2:
			date.AddMonth(inc);
			break;
		case 3:
			date.AddDay(inc);
			break;
		case 4:
			date.showDate();
			break;
		default:
			std::cout << " 다시 입력 ( 1 ~ 5 )" << std::endl;
		}
	}

    return 0;
}