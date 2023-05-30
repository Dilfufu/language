#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

class Date {
    int year_;
    int month_;
    int day_;

    public:
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        int GetCurrentMonthTotalDays(int year, int month);

        void ShowDate();

        /* 생성자도 overloading 가능 */
        Date(int year, int month, int day)
        {
            std::cout << "인자 3개 생성자 호출! " << std::endl; 
            year_ = year;
            month_ = month;
            day_ = day;
        }

        Date() 
        {
            std::cout << "기본 생성자 호출! " << std::endl; 
            year_ = 2012;
            month_ = 7;
            day_ = 12;
        }

};

void Date::SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month != 2) 
    {
        return month_day[month - 1];
    } 
    else if (year % 4 == 0 && year % 100 != 0) 
    {
        return 29;  // 윤년
    } 
    else 
    {
        return 28;
    }
}

void Date::AddDay(int inc) {
    while (true) 
    {
        // 현재 달의 총 일 수
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        // 같은 달 안에 들어온다면;
        if (day_ + inc <= current_month_total_days) 
        {
            day_ += inc;
            return;
        } 
        else 
        {
            // 다음달로 넘어가야 한다.
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc) 
{
    AddYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) 
{ 
    year_ += inc; 
}

void Date::ShowDate() 
{
  std::cout << "오늘은 " 
            << year_ << " 년 " 
            << month_ << " 월 " 
            << day_ << " 일 입니다 " 
            << std::endl;
}

int main()
{
    /* skaskawl - 2023.05.30 : Class Constructor & Default Constructor */
    
    #if 0
    //overloading
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    /*
     * 1단계 : 타입이 일치하는 함수를 찾는다.
     * 2단계 : 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
     *  - Char, unsigned char, short 는 int 로 변환된다.
     *  - Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
     *  - Float 은 double 로 변환된다.
     *  - Enum 은 int 로 변환된다.
     * 3단계 : 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
     *  - 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
     *  - Enum 도 임의의 숫자 타입으로 변환된다 (예를 들어 Enum -> double)
     *  - 0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다.
     *  - 포인터는 void 포인터로 변환된다.
     * 4단계 : 유저 정의된 타입 변환으로 일치하는 것을 찾는다 (https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/)
    **/

    print(a);
    print(b);
    print(c);

    //date class 구현

    //Constructor

    Date day(2011,3,1);
    day.ShowDate();


    day.AddDay(30);
    day.ShowDate();

    day.AddDay(2000);
    day.ShowDate();

    day.SetDate(2012, 1, 31);  // 윤년
    day.AddDay(29);
    day.ShowDate();

    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();

    /* Constructor
     * Date day(2011, 3, 1);         // 암시적 방법 (implicit)
     * Date day = Date(2012, 3, 1);  // 명시적 방법 (explicit)
    **/

    /* Default Constructor */
    Date day(2011,3,1);
    Date day2;

    day.ShowDate();
    day2.ShowDate();

    /* 이것도 가능
    * class Test 
    * {
    *     public:
    *     Test() = default;  // 디폴트 생성자를 정의해라
    * };
    **/
    #else
    //problem

    #endif

    return 0;
}

/*
 * 수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다. 
 * 중학생용 기하학 소프트웨워를 만드는 것인데요, 
 * 클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 다른 하나는 Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 
 * 즉 아래와 같은 두 클래스의 함수들을 모두 정의하세요 (난이도 : 上) 
**/

class Point 
{
    int x,y;

    public:
        Point(int pos_x, int pos_y)
        {
            x = pos_x;
            y = pos_y;
        }
        // 이런거 처음본다.. 먼문법이냐..
        int GetX() const
        {
            return x;
        }
        // 이런거 처음본다.. 먼문법이냐..
        int GetY() const
        {
            return y;
        }
};

class Geometry
{
    private:
        // 점 100 개를 보관하는 배열.
        Point* point_array[100] = { NULL, };
        int num_points;
    
    public:
        Geometry()
        {
            num_points = 0;
        }

        void AddPoint(const Point &point)
        {
            point_array[num_points ++] = new Point(point.GetX(), point.GetY());
        }

        // 모든 점들 간의 거리를 출력하는 함수 입니다.
        void PrintDistance();

        // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
        // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
        // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y) = 0을 기준으로
        // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void printNumMeets();
};

/* 
#include <iostream>
#include <cmath>

class Point {
	int x, y;

public:
	Point(int pos_x, int pos_y) {
		x = pos_x;
		y = pos_y;
	}

	int GetX() { return x; }
	int GetX() const { return x; }
	int GetY() { return y; }
	int GetY() const { return y; }
};

class Geometry {
	Point* point_array[100];	// 점 100개를 보관하는 배열
	int num_points;
public:
	Geometry() {
		num_points = 0;
	}

	void AddPoint(const Point& point) {
		point_array[num_points++] = new Point(point.GetX(), point.GetY());
	}

	// 모든 점들 간의 거리를 출력하는 함수입니다.
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수입니다.
	void PrintNumMeets();

	// point1과 point2를 잇는 직선의 방정식에 insert를 집어넣은 값 출력
	int InsertLineToPoint(const Point* point1, const Point* point2, const Point* insert);
};

void Geometry::PrintDistance() {
	for (int i = 0; i < num_points-1; i++) {
		for (int j = i + 1; j < num_points; j++) {
			std::cout << i + 1 << "번째 점과 " << j + 1 << "번째 점 사이의 거리는 "
				<< sqrt(pow(point_array[i]->GetX() - point_array[j]->GetX(), 2)+ pow(point_array[i]->GetY() - point_array[j]->GetY(), 2))
				<< "입니다." << std::endl;
		}
	}
}

int Geometry::InsertLineToPoint(const Point* point1, const Point* point2, const Point* insert) {
	return (point1->GetX() - point2->GetX()) * (insert->GetX() - point1->GetX()) - (point1->GetY() - point2->GetY()) * (insert->GetY() - point1->GetY());
}

void Geometry::PrintNumMeets() {
	int cnt = 0;

	if (num_points <= 3) {
		std::cout << "점이 부족하여 교점이 없습니다." << std::endl;
		return;
	}
		

	for (int i = 0; i < num_points - 3; i++) {
		for (int j = i + 1; j < num_points-2; j++) {
			for (int k = j + 1; k < num_points - 1; k++) {
				for (int l = k + 1; l < num_points; l++) {
					if (InsertLineToPoint(point_array[i], point_array[j], point_array[k]) * InsertLineToPoint(point_array[i], point_array[j], point_array[l]) <= 0)
						cnt++;
				}
			}
		}
	}

	std::cout << "교점은 총 " << cnt << "개 입니다." << std::endl;
}



int main() {
	// 테스트
	Point pos1(1, 2), pos2(3, 1), pos3(-1, -4), pos4(5,2);
	Geometry Geo;
	Geo.AddPoint(pos1);
	Geo.AddPoint(pos2);
	Geo.AddPoint(pos3);
	Geo.AddPoint(pos4);

	Geo.PrintDistance();
	Geo.PrintNumMeets();

	return 0;
}

 */