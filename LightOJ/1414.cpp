#include <iostream>
#include <sstream>
#include <map>

std::map <std::string, int> month_number = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12}
};

int dates_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{
    public:
        std::string month;
        int date, year;

        Date(std::string m, int d, int y) : month(m), date(d), year(y){}

        friend std::ostream& operator << (std::ostream &, const Date &);
};

std::ostream& operator << (std::ostream& out, const Date &date){
    out << "Month: " << date.month << " Date: " << date.date << " Year: " << date.year;
    return out;
}


int number_of_leap_years_before(int year){
    year--;
    return (year / 4) - (year / 100) + (year / 400);
}

int number_of_leap_years(int start_year, int end_year){
    return number_of_leap_years_before(end_year + 1) - number_of_leap_years_before(start_year);
}

Date parse_date(std::string date_format){
    std::stringstream ss(date_format);
    std::string month, sdate, syear;
    ss >> month >> sdate >> syear;
    int date = std::stoi(sdate);
    int year = std::stoi(syear);
    return Date(month, date, year);
}

bool is_leap_year(int year){
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main(int argc, char const *argv[])
{
    int T, k = 0; std::cin >> T;
    bool flag = false;
    while(T--){
        std::string date_format1, date_format2;
        if(!flag){
            std::getchar();
            flag = true;
        }
        
        std::getline(std::cin, date_format1);
        std::getline(std::cin, date_format2);

        Date date1 = parse_date(date_format1);
        Date date2 = parse_date(date_format2);

        int number_of_leap_days = number_of_leap_years(date1.year, date2.year);

        // if the start date is after february 29
        if(is_leap_year(date1.year) && month_number[date1.month] > 2) {
            number_of_leap_days--;
        }

        // if end date is before february 29
        if(is_leap_year(date2.year) && ((month_number[date2.month] < 2) || (month_number[date2.month] == 2 && date2.date < 29))){
            number_of_leap_days--;  
        } 

        std::cout << "Case " << ++k << ": " << number_of_leap_days << "\n";
    }
    return 0;
}
